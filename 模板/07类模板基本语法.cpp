#include <iostream>
#include <string>

//类模板
//类模板和函数模板的语法非常相似，在template后面写类就可以了
template<typename NameT, typename AgeT>
class Person {
public:

	Person(NameT name, AgeT age) {
		this->_name = name;
		this->_age = age;
	}

	void show() {
		std::cout << "name：" << _name << " age：" << _age << std::endl;
	}

	NameT _name;
	AgeT _age;
};

void test01() {
	Person<std::string, int> p1("孙悟空", 999);
	p1.show();
}

int main() {
	test01();

	return 0;
}