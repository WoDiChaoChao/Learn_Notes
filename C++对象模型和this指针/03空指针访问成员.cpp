#include <iostream>
using namespace std;

//this指针的用途


class Person
{
public:

	void name() {
		cout << "this is Person class" << endl;
	}

	void showage() {
		cout << "age is" << age << endl;
	}

	int age;

private:

};

void test01() {
	Person* p1 = nullptr;
	p1->name();

	p1->showage();
	//报错原因：成员变量age会默认前面有this->age，但是p1=nullptr,所以this = nullptr, 因此空指针指向的age就会报错
}


int main() {
	
	test01();

	system("pause");
	return 0;
}