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

//����ʵ�ֹ��캯��
template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}

//����ʵ�ֳ�Ա����
template<typename T1, typename T2>
void Person<T1, T2>::showPerson() {
	std::cout << "������" << this->m_name << "���䣺" << this->m_age << std::endl;
}