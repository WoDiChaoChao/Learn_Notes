#include <iostream>
using namespace std;

//��̬��Ա����
//1.����ʵ�����Ķ���ͬ����ͬһ���ڴ�ռ�
//2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

class Person
{
public:
	static void func1() {
		m_A = 100;
		//m_B = 200;//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		cout << "static void func1()�ĵ���" << endl;
	}

	static int m_A;
	int m_B;
private:
	
};

int Person::m_A = 200;

void test() {
	Person p;
	p.func1();
	cout << p.m_A << endl;


	Person::func1();
}

int main() {
	test();

	system("pause");
	return 0;
}