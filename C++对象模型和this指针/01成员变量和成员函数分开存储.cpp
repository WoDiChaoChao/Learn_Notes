#include <iostream>
using namespace std;

//成员变量 和 成员函数  分开存储

class Person
{
public:
	int m_A; //成员变量 属于类对象
	static int m_b; //静态成员变量 不属于类对象
	void func(); //成员函数 不属于类对象
	static void func1(); //静态成员函数，不属于类对象

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