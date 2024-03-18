#include <iostream>
using namespace std;

class MyIntager
{
	friend ostream& operator<<(ostream& cout,const MyIntager& myint);
public:
	MyIntager() {
		m_A = 0;
	}
	
	//前置++运算符重载
	MyIntager& operator++() {
		//先++;
		m_A++;
		//再返回结果
		return *this;
	}

	//后置++运算符重载
	MyIntager operator++(int dumpy) {
		//临时变量储存
		MyIntager temp = *this;
		//再++
		m_A++;
		//返回临时变量
		return temp;
	}

private:
	int m_A;
};

ostream& operator<<(ostream& cout, const MyIntager& myint) {
	cout << myint.m_A;
	return cout;
}

void test01() {
	MyIntager myint;
	cout << ++myint << endl;
}

void test02() {
	MyIntager myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}