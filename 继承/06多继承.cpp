#include <iostream>
using namespace std;

class Base1
{
public:
	Base1() {
		m_A = 10;
	}

	int m_A;
private:
};

class Base2
{
public:
	Base2() {
		m_A = 20;
		m_B = 30;
	}
	int m_B;
	int m_A;
private:
};

//��̳��﷨
//class ���� : �̳з�ʽ ����1, �̳з�ʽ ����2...
class Son : public Base1, public Base2
{
public:
	Son() {
		m_C = 100;
	}

	int m_C;

private:
};

void test() {
	Son s;
	//��̳�ͬ����Ա��Ҫд������
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main() {

	test();

	system("pause");
	return 0;
}