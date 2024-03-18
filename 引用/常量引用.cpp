#include <iostream>
using namespace std;

void show(const int& v) {
	//v += 10; //修改之后也会将主函数中的变量也随之修改
	//加入const修饰之后就不可以修改
	cout << v << endl;
}

int main() {

	int a = 10;

	//int& ref = 20;	//引用必须是引用一块合法的内存空间，这行是错误的

	const int& ref = 20; //添加const后解决错误，编译器优化代码：int tmp = 20; int& ref = tmp; tmp临时空间是编译器自动生成的

	//使用场景：修饰函数中不可以被改变的值，防止误操作，加入const后不可以进行更改
	show(a);
	cout << a << endl;

	system("pause");
	return 0;
}