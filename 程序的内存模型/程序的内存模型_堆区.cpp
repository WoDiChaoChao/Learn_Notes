#include <iostream>
using namespace std;

int* func() {

	int* a = new int(10);
	return a;

}

int main() {

	//���������ڳ���ִ��֮��
	//�����ɳ���Ա�Լ������ڴ�Ŀ��ٺ��ͷţ������ڴ�û���ͷţ����������ڳ������֮���Զ��ͷ�
	//�������ڴ��ɹؼ��� new����  delete�ͷ�

	int* p = func();
	cout << *p << endl;
	int b;
	cin >> b;
	cout << *p << endl;	//����ֲ�����a��ŵ��Ƕ������ڴ棬�ں���ִ����ɺ󣬴�ű���a�ĵ�ַ���ͷţ�����a��ַ���ͷ�ǰ���Ѿ��������ĵ�ַ���ظ�p��

	system("pause");
	return 0;
}