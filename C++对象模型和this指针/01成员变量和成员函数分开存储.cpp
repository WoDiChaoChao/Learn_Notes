#include <iostream>
using namespace std;

//��Ա���� �� ��Ա����  �ֿ��洢

class Person
{
public:
	int m_A; //��Ա���� ���������
	static int m_b; //��̬��Ա���� �����������
	void func(); //��Ա���� �����������
	static void func1(); //��̬��Ա�����������������

private:

};

int Person::m_b = 10;

void test01() {
	Person p;
	cout << sizeof(p) << endl;
}

int main() {
	test01();

	system("pause");
	return 0;
}