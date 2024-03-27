#include <iostream>

void Myfunc(int a, int b) {
	std::cout << "普通函数的调用" << std::endl;
}

template<typename T>
void Myfunc(T a, T b) {
	std::cout << "函数模板的调用" << std::endl;
}

template<typename T>
void Myfunc(T a, T b, T c) {
	std::cout << "函数模板重载的调用" << std::endl;
}

void test01() {
	int a = 10;
	int b = 20;
	int c = 30;
	//普通函数和函数模板同时存在时优先调用普通函数
	Myfunc(a, b);

	//可以使用空模板参数列表来强制调用函数模板
	Myfunc<>(a, b);

	//函数模板也可以发生重载
	Myfunc(a, b, c);

	//如果函数模板可以产生更好的匹配，优先调用函数模板
	char x = 'x', y = 'y';
	//普通函数需要char向int的隐式转换，函数模板不用，优先调用函数模板
	Myfunc(x, y);
}

int main() {
	test01();

	return 0;
}