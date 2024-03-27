#include <iostream>

//类模板的成员函数调用时机
//类模板成员函数在定义的时候不会创建，编译可以通过
//只有在确定模板参数列表的类型后，才会被调用

class Person1 {
public:
	void showPerson1() {
		std::cout << "Person1 show" << std::endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		std::cout << "Person2 show" << std::endl;
	}
};

template<typename T>
class MyClass {
public:
	T obj;
	
	void f1(){
		obj.showPerson1();
	}
	
	void f2(){
		obj.showPerson2();
	}
};

//以上代码可以编译通过，因为编译器还不知道类模板中参数列表中的确定类型

void test01(){
	MyClass<Person1> m;
	//在确定了模板参数列表后再调用成员函数，这时成员函数才会被创建
	m.f1();
	//m.f2();
}

int main() {
	test01();

	return 0;
}

