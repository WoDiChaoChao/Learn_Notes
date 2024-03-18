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

//多继承语法
//class 类名 : 继承方式 父类1, 继承方式 父类2...
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
	//多继承同名成员需要写作用域
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main() {

	test();

	system("pause");
	return 0;
}