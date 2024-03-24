#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <sstream>

#include <stdio.h>

void thread_work1(std::string str) {
	std::cout << "str is " << str << std::endl;
}

class background_task {
public:
	void operator() () {
		std::cout << "background_task is called" << std::endl;
	}
};

struct func {
	int& _i;
	func(int &i): _i(i){}
	void operator() () {
		for (int i = 0; i < 3; i++) {
			_i = i;
			std::cout << "_i is " << _i << std::endl;
		}
	}
};

class X {
public:
	void do_some_work() {
		std::cout << "do some work" << std::endl;
	}
};

class thread_guard {
private:
	std::thread& t;
public:
	thread_guard(std::thread& _t):t(_t){}
	~thread_guard() {
		//����߳�û�е��ù�join��joinable()����true
		if (t.joinable()) {
			t.join();
		}
	}
};

void bind_class_oops() {
	X mx;
	std::thread t9(&X::do_some_work, &mx);
	t9.join();
}

void opps() {
	int num = 0;
	func MyFunc(num);
	std::thread t5(MyFunc);

	t5.detach();
}

void catch_exception() {
	int num = 0;
	func Myfunc(num);
	std::thread t6(Myfunc);

	try
	{
		//���߳�����һЩ������ܻᴥ���쳣
	}
	catch (const std::exception& e)
	{
		t6.join();
		throw;
	}
	t6.join();
}

void printf_str(int i, std::string str) {
	std::cout << "i is " << i << " str is " << str << std::endl;
}

void danger_oops(int som_param) {
	char buffer[1024];
	sprintf(buffer, "%i", som_param);

	//char��std::string����ʽת�����߳��п��ܻ���ɱ���
	//���߳�������buffer�����Բ�������ʽ��������������ʱ����buffer�Ѿ�����}���ͷ���
	std::thread t7(printf_str,3,buffer);
	t7.join();
}

void safe_oops(int som_param) {
	char buffer[1024];
	sprintf(buffer, "%i", som_param);

	//��ʾת��
	std::thread t7(printf_str, 3, std::string(buffer));
	t7.join();
}

void change_param(int& param) {
	param++;
}

void ref_oops() {
	int som_param = 10;
	//����Ϊ�������͵�ʱ��Ҫʹ��std::ref����ת��
	std::thread t8(change_param, std::ref(som_param));
	t8.join();
}

void auto_guard() {
	int some_param = 10;
	func f(some_param);
	std::thread g_thread(f);

	//���������̣߳�������ִ�е�}��ʱ����ȶԶ���g����������������ʱ��������߳�g_thread�Ƿ�ִ�����
	thread_guard g(g_thread);

}

int main() {
	std::string hellostr = "hello world!";
	//1.ͨ��()��ʼ��������һ���߳�
	std::thread t1(thread_work1, hellostr);

	//2.���̵߳ȴ����߳�ִ��
	t1.join();

	//3. ����std::thread���͵�ֵ, �����Ĳ���Ϊһ������ָ��,�ú���ָ�뷵��ֵΪbackground_task, ����Ϊvoid
	//std::thread t2(background_task());
	//t2.join();

	std::thread t2((background_task()));
	t2.join();

	std::thread t3{ background_task() };
	t3.join();

	//4.lambda���ʽ
	std::thread t4(
		[](std::string str) {
			std::cout << "str is " << str << std::endl;
		}, hellostr
	);
	t4.join();

	//5.detach()ע������
	opps();

	//6.�쳣����
	catch_exception();
	
	//7.������ʽת��
	danger_oops(3);
	//������� ʹ����ʾת��
	safe_oops(3);

	//8.���ò���
	ref_oops();

	//9. ���Ա�������̲߳���
	bind_class_oops();

	//10. �����߳�
	auto_guard();

	return 0;
}