#include <iostream>
using namespace std;

//thisָ�����;


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
	//����ԭ�򣺳�Ա����age��Ĭ��ǰ����this->age������p1=nullptr,����this = nullptr, ��˿�ָ��ָ���age�ͻᱨ��
}


int main() {
	
	test01();

	system("pause");
	return 0;
}