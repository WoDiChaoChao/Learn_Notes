#include <iostream>
using namespace std;

//������Ĭ�ϲ���
int func(int a = 10, int b = 10, int c = 10) {
	return a + b + c;
}

//ע������
// 
//1.������ĳһ����������Ĭ��ֵ����ô����������������в�����������Ĭ��ֵ
//���´���ᱨ��
//int func2(int a, int b = 10, int c) {
//	return a + b + c;
//}

//2.���������ͺ�������ֻ������һ������Ĭ�ϲ���ֵ
//���´������ᱨ��
//int func3(int a = 10, int b = 20);	//��������
//int func3(int a, int b=30) {
//	return a + b;
//}


int main() {

	//���Դ��ݲ������ĺ�����Ĭ�ϲ���
	cout << func(20,20) << endl;

	//cout << func3() << endl;

	system("pause");
	return 0;
}