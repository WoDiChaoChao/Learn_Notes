#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base.func()�ĵ���" << endl;
	}
	int m_A;
};
class Son : public Base
{
public:
	Son() {
		m_A = 200;
	}
	void func() {
		cout << "Son.fun()�ĵ���" << endl;
	}
	int m_A;
private:

};

void test01() {
	Son s;
	cout << "Son ���е�m_A = " << s.m_A << endl;
	s.func();
	//���ʸ�����������ͬ���ķǾ�̬��Ա�ͺ���Ҫ��������
	cout << "Base ���е�m_A = " << s.Base::m_A << endl;
	s.Base::func();
}

int main() {

	test01();

	system("pause");
	return 0;
}