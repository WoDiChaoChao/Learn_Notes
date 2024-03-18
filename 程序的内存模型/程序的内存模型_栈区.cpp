#include <iostream>
using namespace std;

int* func(int b) {
	b = 10;
	int a = 10;
	return &a;
}

int main() {

	//栈区生成于程序执行之后,由系统自动进行内存的开辟和释放
	//栈区存放的是局部变量和函数的参数(包括形参和实参)
	//栈区的注意事项：不要返回函数中局部变量的地址

	int* p = func(10);
	cout << *p << endl;
	int b;
	cin >> b;
	cout << *p << endl;	//在高版本的vs中，返回栈区中局部变量的地址，会进行保留，前提是中间没有别的操作
	//cout << *p << endl;
	system("pause");
	return 0;
}