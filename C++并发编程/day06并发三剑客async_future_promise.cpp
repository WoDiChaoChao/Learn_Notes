#include <iostream>
#include <thread>
#include <future>
#include <asyncinfo.h>

std::string fetchDataFromDB(std::string data) {
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	return "Data:" + data;
}

void use_async() {	
     //�첽���񷵻ؽ��������				       //�첽������ģʽ   Ҫִ�е��첽����
	std::future<std::string> result = std::async(std::launch::async, fetchDataFromDB, "20");
	/*
	�첽������ģʽ��
	std::launch::deferred	����ģʽ������std::future::get()��std::future::wait()��ʱ��Ż�ȥִ���첽����
	std::launch::async | std::launch::deferred ����ģʽ�����ɱ�����������cpu��ʹ������������첽ִ�л���ͬ��ִ��
	*/
	std::cout << "Main thread do something" << std::endl;

	//ͨ��future�����ȡ�첽����ִ�еĽ��
	//std::future::get()�������ȴ��첽����ִ�����
	std::string ans = result.get();
	std::cout << ans << std::endl;
}

int my_task() {
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "thread is sleep 5 s" << std::endl;
	return 42;
}

void use_package_task_and_future() {
	//ʹ��package_task��װһ������	�������Զ����  int����ֵ ()�޲�
	std::packaged_task<int()> task(my_task);

	//ͨ��get_future�������Ի�ȡstd::future���󣬿���֮��ʲôʱ�����ȡ����˾�ֱ�ӵ���get����
	std::future result = task.get_future();

	//�����Խ���������һ���߳�������
	std::thread t(std::move(task));
	t.detach();

	int res = result.get();
	std::cout << "value is ��" << res << std::endl;
}

void set_value(std::promise<int> prom) {
	prom.set_value(10);
	std::cout << "Thread set value success " << std::endl;
}

void use_promise() {
	//����promise�����첽����Ĳ�����ʲô���;ʹ���ʲô����
	std::promise<int> prom;
	//ͨ��get_future������ȡfuture����
	std::future<int> result = prom.get_future();

	std::thread t(set_value, std::move(prom));

	std::cout << "Main Thread is waiting thread to set value" << std::endl;
	//_Get_value()����ȴ����߳�ִ�н����ŷ��أ����߳�ֻҪͨ��set_value������ֵ���ͻ����̽����ֵ����
	std::cout << "value: " << result._Get_value() << std::endl;
	//����ʹ��join��Ϊ�˷�ֹ���߳�û��������
	t.join();

}

void set_exception(std::promise<void> prom) {
	try
	{
		throw std::runtime_error("runtime error");
	}
	catch (const std::exception& e)
	{
		//���߳�ͨ��set_exception�����쳣
		prom.set_exception(std::current_exception());
	}
}

void use_promise_set_exception() {
	//����promise����
	std::promise<void> prom;
	//��ȡfuture����
	std::future<void> result = prom.get_future();
	//�������߳�ִ���첽����
	std::thread t(set_exception, std::move(prom));
	
	//���߳�����׳��쳣�����߳�Ҫʹ��try catchȥ���񣬷������߳�Ҳ�����
	try
	{
		std::cout << "Main thread is waitting child thread throw exception" << std::endl;
		result.get();
	}
	catch (const std::exception& e)
	{
		std::cout << "child thread error��" << e.what() << std::endl;
	}
	//����ʹ��join��Ϊ�˷�ֹ���߳�û��������
	t.join();
}

void MyFunction(std::promise<int> prom) {
	//�����߳�ִ��������
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Thread sleep 2 s" << std::endl;
	prom.set_value(20);
}

void ThreadFunction(std::shared_future<int> result) {
	try
	{
		int res = result.get();
		std::cout << "Value��" << res << std::endl;
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
	//ͨ��asyncִ���첽����
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
	//1. async + std::futureʵ���첽����ִ�еĻ���ʹ��
	//use_async();

	//2. packaged_task + std::futureʵ���첽����ִ�еĻ���ʹ��
	//use_package_task_and_future();

	//3. promise + std::futureʵ���첽����ִ�еĻ���ʹ��
	//set_value��ȡֵ
	//use_promise();
	//set_exception��ȡ�쳣
	//use_promise_set_exception();

	//4. shared_future�Ļ���ʹ��
	//��һ���첽������Ҫ����߳�ͬʱ����ִ�в�����ɵ�ʱ��
	//�Ϳ���ʹ��shared_future
	//use_shared_future();

	//5. async�첽�����쳣����
	async_exception();

	return 0;
}