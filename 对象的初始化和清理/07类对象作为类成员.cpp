#include <iostream>
using namespace std;

class Phone
{
public:
	Phone(string phone) {
		cout << "Phone 构造函数的调用" << endl;
		phone_name = phone;
	}
	~Phone() {
		cout << "Phone 析构函数的调用" << endl;
	}

	string phone_name;

private:

};

class Person
{
public:

	Person(string name, string phone):m_phone(phone)
		//对于类对象作为初始化列表的操作对象时会先创建出类的对象，再进行赋值，相当于 Phone m_phone = phone;
	{
		cout << "Person 构造函数的调用" << endl;
		m_name = name;
		//m_phone = phone; //这样赋值是错误的，因为这里没有string到Phone的转换
	}

	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	string m_name; //姓名
	Phone m_phone; //手机对象  类对象作为类成员

private:

};

void test() {
	Person p("张三","HuaWei");
	cout << p.m_name << "带着" << p.m_phone.phone_name << "手机" << endl;
}

//类对象作为类成员时，会先创建类成员，再创建本体对象,在析构的时候正好相反

int main() {

	test();

	system("pause");
	return 0;
}