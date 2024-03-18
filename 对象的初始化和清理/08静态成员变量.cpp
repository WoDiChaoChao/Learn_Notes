#include <iostream>
using namespace std;

//静态成员变量
//1.所有实例化的对象共同享有同一块内存空间
//2.类内定义，类外初始化
//3.在程序编译前完成

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
	//静态成员变量的访问方式
	//1.通过对象访问
	Person p;
	cout << p.m_A << endl;

	//2.静态成员不独属于某一个对象，可以用类来访问
	cout << Person::m_A << endl;
}

int main() {

	//test01();
	test02();

	//静态成员变量是由访问权限的
	//cout << Person::m_B << endl;

	system("pause");
	return 0;
}