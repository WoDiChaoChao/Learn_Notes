#include <iostream>
#include <thread>
#include <future>
#include <asyncinfo.h>

std::string fetchDataFromDB(std::string data) {
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	return "Data:" + data;
}

void use_async() {	
     //异步任务返回结果的类型				       //异步并发的模式   要执行的异步任务
	std::future<std::string> result = std::async(std::launch::async, fetchDataFromDB, "20");
	/*
	异步并发的模式：
	std::launch::deferred	这种模式将会在std::future::get()和std::future::wait()的时候才会去执行异步任务
	std::launch::async | std::launch::deferred 这种模式将会由编译器来根据cpu的使用情况来决定异步执行还是同步执行
	*/
	std::cout << "Main thread do something" << std::endl;

	//通过future对象获取异步任务执行的结果
	//std::future::get()会阻塞等待异步任务执行完成
	std::string ans = result.get();
	std::cout << ans << std::endl;
}

int my_task() {
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "thread is sleep 5 s" << std::endl;
	return 42;
}

void use_package_task_and_future() {
	//使用package_task包装一个任务	任务是自定义的  int返回值 ()无参
	std::packaged_task<int()> task(my_task);

	//通过get_future方法可以获取std::future对象，可以之后什么时候想获取结果了就直接调用get方法
	std::future result = task.get_future();

	//还可以将任务在另一个线程上运行
	std::thread t(std::move(task));
	t.detach();

	int res = result.get();
	std::cout << "value is ：" << res << std::endl;
}

void set_value(std::promise<int> prom) {
	prom.set_value(10);
	std::cout << "Thread set value success " << std::endl;
}

void use_promise() {
	//创建promise对象，异步任务的参数是什么类型就创建什么类型
	std::promise<int> prom;
	//通过get_future方法获取future对象
	std::future<int> result = prom.get_future();

	std::thread t(set_value, std::move(prom));

	std::cout << "Main Thread is waiting thread to set value" << std::endl;
	//_Get_value()不会等待子线程执行结束才返回，子线程只要通过set_value设置了值，就会立刻将这个值返回
	std::cout << "value: " << result._Get_value() << std::endl;
	//这里使用join是为了防止子线程没有运行完
	t.join();

}

void set_exception(std::promise<void> prom) {
	try
	{
		throw std::runtime_error("runtime error");
	}
	catch (const std::exception& e)
	{
		//子线程通过set_exception设置异常
		prom.set_exception(std::current_exception());
	}
}

void use_promise_set_exception() {
	//创建promise对象
	std::promise<void> prom;
	//获取future对象
	std::future<void> result = prom.get_future();
	//启动子线程执行异步任务
	std::thread t(set_exception, std::move(prom));
	
	//子线程如果抛出异常，主线程要使用try catch去捕获，否则主线程也会崩溃
	try
	{
		std::cout << "Main thread is waitting child thread throw exception" << std::endl;
		result.get();
	}
	catch (const std::exception& e)
	{
		std::cout << "child thread error：" << e.what() << std::endl;
	}
	//这里使用join是为了防止子线程没有运行完
	t.join();
}

void MyFunction(std::promise<int> prom) {
	//假设线程执行了两秒
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Thread sleep 2 s" << std::endl;
	prom.set_value(20);
}

void ThreadFunction(std::shared_future<int> result) {
	try
	{
		int res = result.get();
		std::cout << "Value：" << res << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void use_shared_future() {
	std::promise<int> prom;
	std::shared_future<int> result = prom.get_future();

	std::thread t1(MyFunction, std::move(prom));

	std::thread t2(ThreadFunction, result);
	std::thread t3(ThreadFunction, result);

	t1.join();
	t2.join();
	t3.join();
}

void may_throw() {
	throw std::runtime_error("runtime error");
}

void async_exception() {
	//通过async执行异步任务
	std::future<void> result = std::async(std::launch::async, may_throw);

	try
	{
		result.get();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main() {
	//1. async + std::future实现异步任务执行的基本使用
	//use_async();

	//2. packaged_task + std::future实现异步任务执行的基本使用
	//use_package_task_and_future();

	//3. promise + std::future实现异步任务执行的基本使用
	//set_value获取值
	//use_promise();
	//set_exception获取异常
	//use_promise_set_exception();

	//4. shared_future的基本使用
	//当一个异步任务需要多个线程同时访问执行才能完成的时候
	//就可以使用shared_future
	//use_shared_future();

	//5. async异步任务异常处理
	async_exception();

	return 0;
}