#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base.func()的调用" << endl;
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
		cout << "Son.fun()的调用" << endl;
	}
	int m_A;
private:

};

void test01() {
	Son s;
	cout << "Son 类中的m_A = " << s.m_A << endl;
	s.func();
	//访问父类中与子类同名的非静态成员和函数要加作用域
	cout << "Base 类中的m_A = " << s.Base::m_A << endl;
	s.Base::func();
}

int main() {

	test01();

	system("pause");
	return 0;
}