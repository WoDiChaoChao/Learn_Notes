#include <iostream>
using namespace std;

int main() {

	int a = 10;
	//编译器自动转化为 int* const ref = &a;
	//将a的地址存放在一个指针常量中，这个指针因为const修饰而不可以更改指向
	int& ref = a;

	ref = 100; //编译器自动转化为 *ref = 10;

	//总结：引用的本质就是指针的常量的定义，赋值，解引用

	system("pause");
	return 0;
}