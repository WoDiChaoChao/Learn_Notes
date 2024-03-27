#include <iostream>

/*
普通函数和函数模板的区别：
	普通函数可以进行隐式类型转换
	函数模板在自动类型推导的时候不会进行隐式类型转换；在显式指定数据类型的时候会进行隐式类型转换
*/

int Add01(int a, int b) {
	return a + b;
}

template<typename T>
T Add02(T a, T b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//std::cout << Add01(a, b) << std::endl;
	//普通函数可以进行隐式类型转换
	std::cout << Add01(a, c) << std::endl;
	//自动类型推导的时候不会进行隐式类型转换
	//错误：std::cout << Add02(a, c) << std::endl;
	//显式指定数据类型的时候会进行隐式类型转换
	//正确：
	std::cout << Add02<int>(a, c) << std::endl;
}

int main() {
	test01();

	return 0;
}