#include <iostream>
using namespace std;

//���ؾֲ�����������
int& test01() {
	int a = 10;		//�ֲ����������ջ��
	return a;
}

//���ؾ�̬����������
int& test02() {
	static int a = 10;	//��̬���������ȫ����
	return a;
}

int main() {

	//int& ref1 = test01();
	//cout << "ref1=" << ref1 << endl;	//���ؾֲ������������ǷǷ��ģ�����õ���ȷ���

	int& ref2 = test02();
	cout << "ref2=" << ref2 << endl;

	//��������������ֵ��������ֵ
	test02() = 1000;
	cout << "ref2=" << ref2 << endl;

	system("pause");
	return 0;
}