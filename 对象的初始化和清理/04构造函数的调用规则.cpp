#include <iostream>
using namespace std;

//默认情况下，C++在定义类的时候，会自动生成三个函数
//1.默认构造函数（函数体为空）
//2.有参构造函数（函数体为空）
//3.拷贝构造函数（对成员属性进行拷贝赋值）

//构造函数调用规则如下：
//1.如果写了有参构造函数，程序员自己不写无参构造函数的话，编译器不会自动调用无参构造函数，但会调用拷贝构造函数
//2.如果写了拷贝构造函数，程序员自己不写无参构造函数和有参构造函数的话，编译器不会自动调用无参构造函数和有参构造函数

class Person
{
public:
	//无参构造函数(默认构造函数)
	Person() {
		cout << "Person 无参构造函数" << endl;
	}
	//有参构造函数
	Person(int a) {
		m_Age = a;
		cout << "Person 有参构造函数" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "Person 拷贝构造函数" << endl;
	}
	//析构函数
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	int m_Age;

private:
};

//void test01() {
//	//Person p; //类 "Person" 不存在默认构造函数	
//
//	Person p1(10);
//	Person p2(p1);
//	cout << "p2的年龄" << p2.m_Age << endl;
//}

void test02() {
	//以下两行代码会报错
	/*Person p1;
	Person p2(10);*/
	
}

int main() {
	
	/*test01();*/
	system("pause");
	return 0;
}