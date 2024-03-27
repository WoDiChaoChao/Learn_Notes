#include <iostream>
#include <string>

//函数模板和类模板的区别

//类模板可以有默认初始化列表参数，函数模板没有
template<typename NameT, typename AgeT = int>
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
	//类模板中没有类型自动推导，只能自定义强制类型
	//错误：Person p("孙悟空", 999);
	Person<std::string, int> p1("孙悟空", 999);
	p1.show();
}

void test02() {
	//当类模板有默认初始化列表参数的时候，可以忽略参数的传递
	Person<std::string> p1("猪八戒", 1000);
	p1.show();
}

int main() {
	//test01();
	test02();
	return 0;
}