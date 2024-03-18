#include <iostream>
using namespace std;

//返回局部变量的引用
int& test01() {
	int a = 10;		//局部变量存放在栈中
	return a;
}

//返回静态变量的引用
int& test02() {
	static int a = 10;	//静态变量存放在全局区
	return a;
}

int main() {

	//int& ref1 = test01();
	//cout << "ref1=" << ref1 << endl;	//返回局部变量的引用是非法的，不会得到正确结果

	int& ref2 = test02();
	cout << "ref2=" << ref2 << endl;

	//引用做函数返回值可以做左值
	test02() = 1000;
	cout << "ref2=" << ref2 << endl;

	system("pause");
	return 0;
}