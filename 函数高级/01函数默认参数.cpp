#include <iostream>
using namespace std;

//函数的默认参数
int func(int a = 10, int b = 10, int c = 10) {
	return a + b + c;
}

//注意事项
// 
//1.函数的某一个参数具有默认值，那么从这个参数向后的所有参数都必须有默认值
//以下代码会报错
//int func2(int a, int b = 10, int c) {
//	return a + b + c;
//}

//2.函数声明和函数定义只能其中一个具有默认参数值
//以下代码编译会报错
//int func3(int a = 10, int b = 20);	//函数声明
//int func3(int a, int b=30) {
//	return a + b;
//}


int main() {

	//可以传递参数更改函数的默认参数
	cout << func(20,20) << endl;

	//cout << func3() << endl;

	system("pause");
	return 0;
}