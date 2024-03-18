#include <iostream>
using namespace std;


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
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	int m_Age;

private:
};

//调用
//1.利用一个创建好的对象来创建一个新对象
void test01() {
	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
	cout << "p2的年龄：" << p2.m_Age << endl;
}

//2.利用函数参数的值传递方式来调用拷贝构造函数
void test02(Person p) {

}

//3.利用函数返回值来调用拷贝构造函数
Person dowork() {
	Person p;
	return p;
}

void test03() {
	Person p = dowork();	//VS高版本中进行了返回值优化，这里不会调用拷贝构造函数
}

int main() {

	//test01();
	/*Person p;
	test02(p);
	*/
	test03();
	system("pause");
	return 0;
}