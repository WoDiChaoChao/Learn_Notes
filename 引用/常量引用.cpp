#include <iostream>
using namespace std;

void show(const int& v) {
	//v += 10; //�޸�֮��Ҳ�Ὣ�������еı���Ҳ��֮�޸�
	//����const����֮��Ͳ������޸�
	cout << v << endl;
}

int main() {

	int a = 10;

	//int& ref = 20;	//���ñ���������һ��Ϸ����ڴ�ռ䣬�����Ǵ����

	const int& ref = 20; //���const�������󣬱������Ż����룺int tmp = 20; int& ref = tmp; tmp��ʱ�ռ��Ǳ������Զ����ɵ�

	//ʹ�ó��������κ����в����Ա��ı��ֵ����ֹ�����������const�󲻿��Խ��и���
	show(a);
	cout << a << endl;

	system("pause");
	return 0;
}