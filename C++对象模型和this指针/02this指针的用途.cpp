#include <iostream>
using namespace std;

//thisָ�����;


class Person
{
public:

	Person(int age) {
		this->age = age; //��������ظ������� thisָ��ָ����� ���ó�Ա���������Ķ���
	}


	//����*thisָ��
	Person& addage(Person &p) {
		this->age += p.age;

		return *this;
	}

	int age;

private:

};

void test01() {
	Person p1(10);

	cout << "p1�����䣺" << p1.age << endl;
}

void test02() {
	Person p1(10);
	Person p2(10);

	p2.addage(p1).addage(p1);
	cout << "p2�����䣺" << p2.age << endl;
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}