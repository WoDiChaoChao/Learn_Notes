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
	p("hello world"); //��Ϊ����������������غͺ������õ��﷨��࣬����Ҳ�зº���
}

int main() {

	test();

	system("pause");
	return 0;
}