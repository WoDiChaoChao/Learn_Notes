#include <iostream>
using namespace std;

int* func(int b) {
	b = 10;
	int a = 10;
	return &a;
}

int main() {

	//ջ�������ڳ���ִ��֮��,��ϵͳ�Զ������ڴ�Ŀ��ٺ��ͷ�
	//ջ����ŵ��Ǿֲ������ͺ����Ĳ���(�����βκ�ʵ��)
	//ջ����ע�������Ҫ���غ����оֲ������ĵ�ַ

	int* p = func(10);
	cout << *p << endl;
	int b;
	cin >> b;
	cout << *p << endl;	//�ڸ߰汾��vs�У�����ջ���оֲ������ĵ�ַ������б�����ǰ�����м�û�б�Ĳ���
	//cout << *p << endl;
	system("pause");
	return 0;
}