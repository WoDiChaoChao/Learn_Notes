#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 10;

static int s_g_a = 10;
static int s_g_b = 10;

const int c_g_a = 10;

int main() {

	//ȫ���������ڳ���ִ��֮ǰ
	//ȫ������� ȫ�ֱ�������̬����������

	int a = 10;
	cout << "�ֲ����� a �ĵ�ַΪ��" << (int)&a << endl;

	//1.ȫ�ֱ���
	cout << "ȫ�ֱ��� g_a �ĵ�ַΪ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ��� g_b �ĵ�ַΪ��" << (int)&g_b << endl;

	//2.��̬�ֲ�����
	static int s_l_a = 10;
	static int s_l_b = 10;
	cout << "��̬�ֲ����� s_l_a �ĵ�ַΪ��" << (int)&s_l_a << endl;
	cout << "��̬�ֲ����� s_l_b �ĵ�ַΪ��" << (int)&s_l_b << endl;

	//3.��̬ȫ�ֱ���
	cout << "��̬ȫ�ֱ��� s_g_a �ĵ�ַΪ��" << (int)&s_g_a << endl;
	cout << "��̬ȫ�ֱ��� s_g_b �ĵ�ַΪ��" << (int)&s_g_b << endl;

	//4.�������ַ���������const���ε�ȫ�ֱ�����Ҳ��ȫ�ֳ�����
	cout << "�ַ��������ĵ�ַΪ��" << (int)&"hello world" << endl;
	cout << "const���ε�ȫ�ֱ��� c_g_a �ĵ�ַΪ��" << (int)&c_g_a << endl;

	const int c_l_a = 10;
	cout << "const���εľֲ����� c_l_a �ĵ�ַΪ��" << (int)&c_l_a << endl;

	system("pause");
	return 0;
}