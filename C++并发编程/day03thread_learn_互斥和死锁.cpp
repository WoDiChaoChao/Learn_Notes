#include <iostream>
#include <thread>
#include <mutex>
#include <stack>

std::mutex mtex;
int share_data = 100;

void use_lock() {
	while (true) {
		mtex.lock();
		share_data++;
		std::cout << "current thread is " << std::this_thread::get_id() << std::endl;
		std::cout << "share_data is " << share_data << std::endl;
		mtex.unlock();
		std::this_thread::sleep_for(std::chrono::microseconds(10));
	}
}

void test_lock_1() {
	std::thread t1(use_lock);
	std::thread t2([]() {
		while (true) {
			//手动加锁和解锁
			mtex.lock();
			share_data--;
			std::cout << "current thread is " << std::this_thread::get_id() << std::endl;
			std::cout << "share_data is " << share_data << std::endl;
			mtex.unlock();
			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
		});

	t1.join();
	t2.join();
}

void test_lock_2() {
	std::thread t1(use_lock);
	std::thread t2([]() {
		while (true) {
			//使用lock_guard 自动进行加锁和解锁
			//lock_guard的定义方式
			//lock_guard会随着局部作用域}的结束而自动进行解锁，防止忘记手动解锁
			{
				std::lock_guard<std::mutex> lock(mtex);
				share_data--;
				std::cout << "current thread is " << std::this_thread::get_id() << std::endl;
				std::cout << "share_data is " << share_data << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
		});

	t1.join();
	t2.join();
}

class safethread_stack {
private:
	std::stack<int> safe_stack;
	mutable std::mutex mtx;
public:
	safethread_stack(){}
	safethread_stack(const safethread_stack& other) {
		std::lock_guard<std::mutex> lock(other.mtx);
		this->safe_stack = other.safe_stack;
	}

	void push(int element) {
		std::lock_guard<std::mutex> lock(this->mtx);
		safe_stack.push(element);
	}

	int pop() {
		std::lock_guard<std::mutex> lock(this->mtx);
		auto element = safe_stack.top();
		safe_stack.pop();
		return element;
	}

	//危险代码
	bool empty()const {
		std::lock_guard<std::mutex> lock(this->mtx);
		//在只读操作函数中返回一个对象，外部再判断这个对象的时候就已经没锁了，由于线程执行的时机
		//可能会造成多个线程同时访问同一个对象
		return safe_stack.empty();
	}
};

void test_safethread_stack1() {
	safethread_stack s;
	s.push(1);

	std::thread t1([&s]() {
		if (!s.empty()) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			s.pop();
		}
	});

	std::thread t2([&s]() {
		if (!s.empty()) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			s.pop();
		}
	});

	t1.join();
	t2.join();
}

std::mutex t_lock1;
std::mutex t_lock2;
int ma = 0;
int mb = 1;

void dead_lock1() {
	while (true) {
		std::cout << "dead_lock 1 begin" << std::endl;
		t_lock1.lock();
		ma = 1024;
		t_lock2.lock();
		mb = 2048;
		t_lock2.unlock();
		t_lock1.unlock();
		std::cout << "dead_lock 1 end" << std::endl;
	}
	

}

void dead_lock2() {
	while (true) {
		std::cout << "dead_lock 2 begin" << std::endl;
		t_lock2.lock();
		ma = 1024;
		t_lock1.lock();
		mb = 2048;
		t_lock1.unlock();
		t_lock2.unlock();
		std::cout << "dead_lock 2 end" << std::endl;
	}
	

}

void test_dead_lock() {
	std::thread t1(dead_lock1);
	std::thread t2(dead_lock2);

	t1.join();
	t2.join();
}

//加锁和解锁作为原子操作解耦合，各自只管理自己的功能
void atomic_lock1() {

	std::cout << "lock_1 is begin " << std::endl;
	t_lock1.lock();
	ma = 1024;
	t_lock1.unlock();
	std::cout << "lock_1 is end " << std::endl;

}

void atomic_lock2() {

	std::cout << "lock_2 is begin " << std::endl;
	t_lock2.lock();
	mb = 2048;
	t_lock2.unlock();
	std::cout << "lock_2 is end " << std::endl;
	
}

void safe_lock1() {
	while (true) {
		atomic_lock1();
		atomic_lock2();
	}
}

void safe_lock2() {
	while (true) {
		atomic_lock2();
		atomic_lock1();
	}
}

void test_safe_lock() {
	std::thread t1(safe_lock1);
	std::thread t2(safe_lock2);

	t1.join();
	t2.join();
}

void function1() {
	std::lock(t_lock1, t_lock2);
	std::lock_guard<std::mutex> lock1(t_lock1, std::adopt_lock);
	std::lock_guard<std::mutex> lock2(t_lock2, std::adopt_lock);

	ma = 1024;
	mb = 2048;

}

void function2() {
	std::lock(t_lock1, t_lock2);
	std::lock_guard<std::mutex> lock1(t_lock1, std::adopt_lock);
	std::lock_guard<std::mutex> lock2(t_lock2, std::adopt_lock);

	ma = 1024;
	mb = 2048;

}

void test_same_lock() {
	std::thread t1(function1);
	std::thread t2(function2);
	t1.join();
	t2.join();
}



int main() {
	//1.互斥锁 mutex	手动加锁和解锁
	//test_lock_1();
	//2.互斥锁 mutex	自动加锁和解锁
	//test_lock_2();

	//3.多线程访问时判断栈是否为空，此后两个线程同时出栈，可能会造成崩溃。
	//test_safethread_stack1();

	//4.死锁是如何造成的
	//test_dead_lock();

	//5.避免死锁的一个方式就是将加锁和解锁的功能封装为独立的函数，
	test_safe_lock();

	//6. 另外解决死锁的问题是对多个锁同时加锁
	test_same_lock();
	return 0;
}