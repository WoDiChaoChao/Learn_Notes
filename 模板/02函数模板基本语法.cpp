#include <iostream>

/*
语法：
template<typename T>
template --- 声明创建模板
typename --- 
*/

//两个整型交换的函数
void swapInt(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//两个浮点型交换的函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	std::cout << "a=" << a << "b=" << b << std::endl;
	swapInt(a, b);
	std::cout << "a=" << a << "b=" << b << std::endl;
}

//函数模板
template<typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错,T是一个通用数据类型
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test02() {
	int a = 10;
	int b = 20;
	std::cout << "a = " << a << " b = " << b << std::endl;
	//利用函数模板进行交换
	//函数模板的两种使用方式
	//1. 类型自动推导
	//mySwap(a, b); 
	//2. 显示指定数据类型
	mySwap<int>(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	
}

int main() {
	//test01();
	test02();
	return 0;
}