#include <iostream>
using namespace std;

//静态成员函数
//1.所有实例化的对象共同享有同一块内存空间
//2.静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func1() {
		m_A = 100;
		//m_B = 200;//静态成员函数只能访问静态成员变量
		cout << "static void func1()的调用" << endl;
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