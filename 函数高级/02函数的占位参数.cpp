#include <iostream>
using namespace std;

//函数的占位参数
//语法：函数返回值类型 函数名 (数据类型){}

void func1(int) {
	cout << "hello world" << endl;
}

//占位参数也可以有默认值
void func2(int = 10) {
	cout << "hello world" << endl;
}

int main() {

	func1(10);
	func2();
	system("pause");
	return 0;
}