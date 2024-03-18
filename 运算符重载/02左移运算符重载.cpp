#include <iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	//利用成员函数重载左移运算符
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

//只能利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p) { //简化 cout << p
	cout << p.m_A << "   " << p.m_B << endl;

	return cout;
}

void test() {
	Person p(10,10);
	cout << p << endl; //返回cout，可以链式调用
}

int main() {

	test();


	system("pause");
	return 0;
}