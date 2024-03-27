#include <iostream>

/*
注意事项：
	自动类型推导，必须推导出一致的数据类型T才可以使用
	模板必须要确定出T的数据类型，才可以使用
*/

template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//自动类型推导，必须推导出一致的数据类型T才可以使用
	//正确： mySwap(a, b);
	//错误： mySwap(a, c);
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
}

template<typename T>
void func() {
	std::cout << "func 调用" << std::endl;
}

void test02() {
	//模板必须要确定出T的数据类型，才可以使用
	//错误：func();
	//正确：func<int>();
}

int main() {

	return 0;
}