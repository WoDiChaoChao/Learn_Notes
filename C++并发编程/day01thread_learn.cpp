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
		//如果线程没有调用过join，joinable()返回true
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
		//主线程做了一些事情可能会触发异常
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

	//char向std::string的隐式转换在线程中可能会造成崩溃
	//在线程启动后buffer才能以参数的形式传给函数，但此时可能buffer已经随着}而释放了
	std::thread t7(printf_str,3,buffer);
	t7.join();
}

void safe_oops(int som_param) {
	char buffer[1024];
	sprintf(buffer, "%i", som_param);

	//显示转换
	std::thread t7(printf_str, 3, std::string(buffer));
	t7.join();
}

void change_param(int& param) {
	param++;
}

void ref_oops() {
	int som_param = 10;
	//参数为引用类型的时候，要使用std::ref进行转换
	std::thread t8(change_param, std::ref(som_param));
	t8.join();
}

void auto_guard() {
	int some_param = 10;
	func f(some_param);
	std::thread g_thread(f);

	//利用守卫线程，当函数执行到}的时候会先对对象g进行析构，析构的时候会检查子线程g_thread是否执行完毕
	thread_guard g(g_thread);

}

int main() {
	std::string hellostr = "hello world!";
	//1.通过()初始化并启动一个线程
	std::thread t1(thread_work1, hellostr);

	//2.主线程等待子线程执行
	t1.join();

	//3. 返回std::thread类型的值, 函数的参数为一个函数指针,该函数指针返回值为background_task, 参数为void
	//std::thread t2(background_task());
	//t2.join();

	std::thread t2((background_task()));
	t2.join();

	std::thread t3{ background_task() };
	t3.join();

	//4.lambda表达式
	std::thread t4(
		[](std::string str) {
			std::cout << "str is " << str << std::endl;
		}, hellostr
	);
	t4.join();

	//5.detach()注意事项
	opps();

	//6.异常处理
	catch_exception();
	
	//7.慎用隐式转换
	danger_oops(3);
	//解决方法 使用显示转换
	safe_oops(3);

	//8.引用参数
	ref_oops();

	//9. 类成员函数做线程参数
	bind_class_oops();

	//10. 守卫线程
	auto_guard();

	return 0;
}