#include <iostream>
using namespace std;

//1.����Ϊ���õĺ�������
void func1(int& a) {
	cout << "func1(int &a)" << endl;
}

void func1(const int& a) {
	cout << "func1(const int &a)" << endl;
}

//2.����Ĭ�ϲ����ĺ�������
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

	//func2(10); //���������������壬��������Ĭ�ϲ����ͺ�����������

	system("pause");
	return 0;
}