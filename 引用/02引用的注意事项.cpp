#include <iostream>
using namespace std;

int main() {

	int a = 10;

	//1.引用必须初始化
	//int& b;	//报错
	int& b = a;

	//2.引用之后不可以更改
	int c = 20;
	b = c;  //这不是更改引用，是赋值操作
	system("pause");
	return 0;
}