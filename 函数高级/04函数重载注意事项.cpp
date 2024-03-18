#include <iostream>
using namespace std;

//1.参数为引用的函数重载
void func1(int& a) {
	cout << "func1(int &a)" << endl;
}

void func1(const int& a) {
	cout << "func1(const int &a)" << endl;
}

//2.带有默认参数的函数重载
void func2(int a, int b = 10) {
	cout << "func2(int a, int b = 10)" << endl;
}

void func2(int a) {
	cout << "func2(int a)" << endl;
}

int main() {

	int a = 10;
	func1(a);//int &a = a;
	func1(10);//const int &a = 10;

	//func2(10); //这种情况会出现歧义，尽量避免默认参数和函数重载相遇

	system("pause");
	return 0;
}