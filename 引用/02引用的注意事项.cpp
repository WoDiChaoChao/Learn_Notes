#include <iostream>
using namespace std;

int main() {

	int a = 10;

	//1.���ñ����ʼ��
	//int& b;	//����
	int& b = a;

	//2.����֮�󲻿��Ը���
	int c = 20;
	b = c;  //�ⲻ�Ǹ������ã��Ǹ�ֵ����
	system("pause");
	return 0;
}