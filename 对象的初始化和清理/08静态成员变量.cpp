#include <iostream>
using namespace std;

//��̬��Ա����
//1.����ʵ�����Ķ���ͬ����ͬһ���ڴ�ռ�
//2.���ڶ��壬�����ʼ��
//3.�ڳ������ǰ���

class Person
{
public:
	static int m_A;

private:
	static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01() {

	Person p1;
	p1.m_A = 100;
	cout << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p1.m_A << endl;

}

void test02() {
	//��̬��Ա�����ķ��ʷ�ʽ
	//1.ͨ���������
	Person p;
	cout << p.m_A << endl;

	//2.��̬��Ա��������ĳһ�����󣬿�������������
	cout << Person::m_A << endl;
}

int main() {

	//test01();
	test02();

	//��̬��Ա�������ɷ���Ȩ�޵�
	//cout << Person::m_B << endl;

	system("pause");
	return 0;
}