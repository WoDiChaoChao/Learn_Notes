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

			//wait���ж�num�Ƿ����1�����ݵڶ����������ص�true��false���ж��Ƿ���Ҫ���̹߳���
			//����true���������ִ��֮����߼�
			//����false���Ὣ�̹߳����������ͷ������ȴ������̻߳���
			cvA.wait(lock, []() {
				return num == 1;
				});

			std::cout << "Thread A print 1" << std::endl;
			num++;
			//���ѹ����B�߳�
			cvB.notify_one();
		}
		
	});

	std::thread t2([]() {
		while (true) {
			std::unique_lock<std::mutex> lock(num_mtx);

			//wait���ж�num�Ƿ����1�����ݵڶ����������ص�true��false���ж��Ƿ���Ҫ���̹߳���
			//����true���������ִ��֮����߼�
			//����false���Ὣ�̹߳����������ͷ������ȴ������̻߳���
			cvB.wait(lock, []() {
				return num == 2;
				});

			std::cout << "Thread B print 2" << std::endl;
			num--;
			//���ѹ����B�߳�
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
		//��������Ƿ�ֹ�ڿ�����ʱ���������̶߳Կ�����������޸�
		std::lock_guard<std::mutex> lock(other.q_mtx);
		this->q = other.q;
	}

	void push(int& value) {
		std::lock_guard<std::mutex> lock(this->q_mtx);
		this->q.push(value);
		//���ѹ����pop����
		q_cv.notify_all();
	}

	void wait_and_pop(int& value) {
		std::unique_lock<std::mutex> lock(this->q_mtx);
		//����Ϊ�յ�ʱ���̹߳���
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
	//�����ʵ�������߳̽�������1 �� 2
	//1. ����ʵ��
	//PoorImpleman();
	//2.������������ʵ��
	//ResonableImplemention();

	//mutex����������������ʵ���̰߳�ȫ����
	test_ThreadSafe_queue();
	return 0;
}