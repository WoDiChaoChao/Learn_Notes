#include <iostream>

//类模板做函数参数
template<typename T1,typename T2>
class Person{
public:

	Person(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}

	void showPerson() {
		std::cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << std::endl;
	}

	T1 m_name;
	T2 m_age;
};

//1. 直接指定传入参数类型
void printPerson1(Person<std::string, int>& p) {
	p.showPerson();
}

void test01() {
	Person<std::string, int> p("孙悟空", 100);
	printPerson1(p);
}

//2. 函数参数模板化
template<typename T1,typename T2>
void printPerson2(Person<T1,T2>& p) {
	p.showPerson();
}

void test02() {
	Person<std::string, int> p("猪八戒", 200);
	printPerson2(p);
}

//3. 直接将类模板化
template<typename T>
void printPerson3(T& p) {
	p.showPerson();
}

void test03() {
	Person<std::string, int> p("唐僧", 200);
	printPerson3(p);
}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}