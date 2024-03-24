#include <iostream>
#include <thread>
#include <vector>

void some_function() {
	std::cout << "some_function()的调用" << std::endl;
}

void some_other_function() {
	std::cout << "some_other_function()的调用" << std::endl;
}
/*
void dangerous_use() {
	std::thread t1(some_function);
	//在std::thread中不能使用拷贝构造的方式进行赋值，只能使用std::move
	std::thread t2 = std::move(t1);
	
	t1 = std::thread(some_other_function);

	std::thread t3 = std::move(t2);
	t1 = std::move(t3);

	std::this_thread::sleep_for(std::chrono::seconds(2000));
}
*/

void use_vector() {
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++) {
		threads.emplace_back(some_function);
	}

	for (auto& mt : threads) {
		mt.join();
	}
}

int main() {
	//1.不要将一个线程的管理权交给一个已经绑定线程的变量
	//dangerous_use();

	//2. 容器存储
	use_vector();

	//3. 识别线程
	std::thread t([] {
		std::cout << "hello world" << std::endl;
		});
	t.join();
	std::cout<<t.get_id();

	return 0;
}