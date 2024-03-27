#pragma once
#include <iostream>
#include <string>

template<typename T1, typename T2>
class Person {
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_name;
	T2 m_age;
};

//类外实现构造函数
template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}

//类外实现成员函数
template<typename T1, typename T2>
void Person<T1, T2>::showPerson() {
	std::cout << "姓名：" << this->m_name << "年龄：" << this->m_age << std::endl;
}