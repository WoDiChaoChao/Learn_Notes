#include <iostream>
#include <string>
//��ģ����ļ���д������ģ��������Ͷ����Լ���Ա������ʵ��д��һ���ļ��У���׺��Ϊ.hpp
#include "Person.hpp"

void test01() {
	Person<std::string, int> p("�����", 100);
	p.showPerson();
}

int main() {
	test01();

	return 0;
}