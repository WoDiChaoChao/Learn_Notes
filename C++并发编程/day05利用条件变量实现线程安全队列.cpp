#include <iostream>
#include <thread>
#include <mutex>
#include <queue>


std::mutex num_mtx;
std::condition_variable cvA;
std::condition_variable cvB;
int num = 1;

void PoorImpleman() {
	std::thread t1([]() {
		while (true) {
			{
				std::lock_guard<std::mutex> lock(num_mtx);
				if (num == 1) {
					std::cout << "Thread A print 1" << std::endl;
					num++;
					continue;
				}
			}
			std::this_thread::sleep_for(std::chrono::microseconds(500));
		}
	});

	std::thread t2([]() {
		while (true) {
			{
				std::lock_guard<std::mutex> lock(num_mtx);
				if (num == 2) {
					std::cout << "Thread B print 2" << std::endl;
					num--;
					continue;
				}
			}
			std::this_thread::sleep_for(std::chrono::microseconds(500));
		}
	});
	t1.join();
	t2.join();
}

void ResonableImplemention() {
	std::thread t1([]() {
		while (true) {
			std::unique_lock<std::mutex> lock(num_mtx);

			//wait会判断num是否等于1，根据第二个参数返回的true或false来判断是否需要将线程挂起
			//返回true，会加锁，执行之后的逻辑
			//返回false，会将线程挂起阻塞，释放锁，等待其他线程唤醒
			cvA.wait(lock, []() {
				return num == 1;
				});

			std::cout << "Thread A print 1" << std::endl;
			num++;
			//唤醒挂起的B线程
			cvB.notify_one();
		}
		
	});

	std::thread t2([]() {
		while (true) {
			std::unique_lock<std::mutex> lock(num_mtx);

			//wait会判断num是否等于1，根据第二个参数返回的true或false来判断是否需要将线程挂起
			//返回true，会加锁，执行之后的逻辑
			//返回false，会将线程挂起阻塞，释放锁，等待其他线程唤醒
			cvB.wait(lock, []() {
				return num == 2;
				});

			std::cout << "Thread B print 2" << std::endl;
			num--;
			//唤醒挂起的B线程
			cvA.notify_one();
		}

	});
	t1.join();
	t2.join();
}

class ThreadSafeQueue {
public:
	ThreadSafeQueue(){}
	ThreadSafeQueue(const ThreadSafeQueue& other) {
		//这里加锁是防止在拷贝的时候有其他线程对拷贝对象进行修改
		std::lock_guard<std::mutex> lock(other.q_mtx);
		this->q = other.q;
	}

	void push(int& value) {
		std::lock_guard<std::mutex> lock(this->q_mtx);
		this->q.push(value);
		//唤醒挂起的pop操作
		q_cv.notify_all();
	}

	void wait_and_pop(int& value) {
		std::unique_lock<std::mutex> lock(this->q_mtx);
		//队列为空的时候线程挂起
		q_cv.wait(lock, [this]() {
			return !q.empty();
			});
		value = q.front();
		q.pop();
	}

private:
	std::queue<int> q;
	mutable std::mutex q_mtx;
	std::condition_variable q_cv;
};

void test_ThreadSafe_queue() {
	ThreadSafeQueue safe_queue;
	std::mutex mtx;

	std::thread Procedure([&]() {
		for (int i = 1;;i++) {
			safe_queue.push(i);
			{
				std::lock_guard<std::mutex> lock(mtx);
				std::cout << "Procedure produce " << i << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(200));
		}
	});

	std::thread Consumer([&]() {
		int value;
		while (true) {
			safe_queue.wait_and_pop(value);
			{
				std::lock_guard<std::mutex> lock(mtx);
				std::cout << "Consumer consumes " << value << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(200));
		}
	});

	Procedure.join();
	Consumer.join();

}

int main() {
	//如果想实现两个线程交替输入1 和 2
	//1. 不良实现
	//PoorImpleman();
	//2.利用条件变量实现
	//ResonableImplemention();

	//mutex互斥量和条件变量实现线程安全队列
	test_ThreadSafe_queue();
	return 0;
}