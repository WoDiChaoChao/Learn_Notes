#include <iostream>
using namespace std;

//函数重载的条件：
//1.函数名相同
//2.函数需要在同一个作用域下
//3.函数的参数个数不一样，类型不一样，顺序不一样

void func(int a) {
	cout << "func(int a)" << endl;
}

void func(int a,int b) {
	cout << "func(int a,int b)" << endl;
}

void func(double a) {
	cout << "func(double a)" << endl;
}

void func(int a,double b) {
	cout << "func(int a,double b)" << endl;
}

void func(double b,int a) {
	cout << "func(double b,int a)" << endl;
}

//注意事项
//函数重载不能有函数返回类型
//以下代码编译会出错
//int func(int a, int b, int c) {
//	cout << "func(int a, int b, int c)" << endl;
//}

int main() {

	func(10);
	func(10, 10);
	func(3.14);
	func(10, 3.14);
	func(3.14, 10);
	/*func(10, 10, 10);*/
	
	system("pause");
	return 0;
}