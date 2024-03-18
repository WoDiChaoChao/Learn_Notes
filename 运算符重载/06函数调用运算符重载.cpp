#include <iostream>
using namespace std;

class Person
{
public:

	void operator()(string text) {
		cout << text << endl;
	}

};

void test() {
	Person p;
	p("hello world"); //因为函数调用运算符重载和函数调用的语法差不多，所以也叫仿函数
}

int main() {

	test();

	system("pause");
	return 0;
}