#include <iostream>
using namespace std;

//this指针的用途


class Person
{
public:

	Person(int age) {
		this->age = age; //解决名称重复的问题 this指针指向的是 调用成员函数所属的对象
	}


	//返回*this指针
	Person& addage(Person &p) {
		this->age += p.age;

		return *this;
	}

	int age;

private:

};

void test01() {
	Person p1(10);

	cout << "p1的年龄：" << p1.age << endl;
}

void test02() {
	Person p1(10);
	Person p2(10);

	p2.addage(p1).addage(p1);
	cout << "p2的年龄：" << p2.age << endl;
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}