#include <iostream>
using namespace std;

int main() {

	int a = 10;
	//�������Զ�ת��Ϊ int* const ref = &a;
	//��a�ĵ�ַ�����һ��ָ�볣���У����ָ����Ϊconst���ζ������Ը���ָ��
	int& ref = a;

	ref = 100; //�������Զ�ת��Ϊ *ref = 10;

	//�ܽ᣺���õı��ʾ���ָ��ĳ����Ķ��壬��ֵ��������

	system("pause");
	return 0;
}