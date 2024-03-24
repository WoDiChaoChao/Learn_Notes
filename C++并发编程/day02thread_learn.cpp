#include <iostream>
#include <thread>
#include <vector>

void some_function() {
	std::cout << "some_function()�ĵ���" << std::endl;
}

void some_other_function() {
	std::cout << "some_other_function()�ĵ���" << std::endl;
}
/*
void dangerous_use() {
	std::thread t1(some_function);
	//��std::thread�в���ʹ�ÿ�������ķ�ʽ���и�ֵ��ֻ��ʹ��std::move
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
	//1.��Ҫ��һ���̵߳Ĺ���Ȩ����һ���Ѿ����̵߳ı���
	//dangerous_use();

	//2. �����洢
	use_vector();

	//3. ʶ���߳�
	std::thread t([] {
		std::cout << "hello world" << std::endl;
		});
	t.join();
	std::cout<<t.get_id();

	return 0;
}