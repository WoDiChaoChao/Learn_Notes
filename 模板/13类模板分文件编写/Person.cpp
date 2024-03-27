#include <iostream>
#include <string>
//类模板分文件编写：把类模板的声明和定义以及成员函数的实现写在一个文件中，后缀改为.hpp
#include "Person.hpp"

void test01() {
	Person<std::string, int> p("孙悟空", 100);
	p.showPerson();
}

int main() {
	test01();

	return 0;
}