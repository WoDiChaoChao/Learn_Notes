#include <iostream>
using namespace std;

//�������ص�������
//1.��������ͬ
//2.������Ҫ��ͬһ����������
//3.�����Ĳ���������һ�������Ͳ�һ����˳��һ��

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

//ע������
//�������ز����к�����������
//���´����������
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