#include <iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	//���ó�Ա�����������������
	//void operator<<(cout) { //p.operator<<(cout)  --> p << cout

	//}

	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}

private:
	int m_A;
	int m_B;
};

//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream& cout, Person& p) { //�� cout << p
	cout << p.m_A << "   " << p.m_B << endl;

	return cout;
}

void test() {
	Person p(10,10);
	cout << p << endl; //����cout��������ʽ����
}

int main() {

	test();


	system("pause");
	return 0;
}