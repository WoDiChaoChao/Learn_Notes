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
			//�ֶ������ͽ���
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
			//ʹ��lock_guard �Զ����м����ͽ���
			//lock_guard�Ķ��巽ʽ
			//lock_guard�����žֲ�������}�Ľ������Զ����н�������ֹ�����ֶ�����
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

	//Σ�մ���
	bool empty()const {
		std::lock_guard<std::mutex> lock(this->mtx);
		//��ֻ�����������з���һ�������ⲿ���ж���������ʱ����Ѿ�û���ˣ������߳�ִ�е�ʱ��
		//���ܻ���ɶ���߳�ͬʱ����ͬһ������
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

//�����ͽ�����Ϊԭ�Ӳ�������ϣ�����ֻ�����Լ��Ĺ���
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
	//1.������ mutex	�ֶ������ͽ���
	//test_lock_1();
	//2.������ mutex	�Զ������ͽ���
	//test_lock_2();

	//3.���̷߳���ʱ�ж�ջ�Ƿ�Ϊ�գ��˺������߳�ͬʱ��ջ�����ܻ���ɱ�����
	//test_safethread_stack1();

	//4.�����������ɵ�
	//test_dead_lock();

	//5.����������һ����ʽ���ǽ������ͽ����Ĺ��ܷ�װΪ�����ĺ�����
	test_safe_lock();

	//6. �����������������ǶԶ����ͬʱ����
	test_same_lock();
	return 0;
}