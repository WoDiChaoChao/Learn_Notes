/*
在使用多态的时候，我们需要的更是子类中的函数，父类中的函数基本上没什么用
那么我们就可以把这个基类写成抽象类

因此可以把虚函数写成纯虚函数
纯虚函数语法：virtual 返回值类型 函数名 (参数列表) = 0;

当类中有了纯虚函数，这个类也称为抽象类

抽象类特点：
无法实例化对象
子类必须重写抽象类中的纯虚函数，否则也是抽象类，无法实例化对象

*/

#include <iostream>
using namespace std;

//抽象类
class Base {
public:
	//纯虚函数
	virtual void func() = 0;
};

class Son : public Base {
public:
	virtual void func() {
		cout << "func函数的调用" << endl;
	}
};

void test01() {
	//Base base; //抽象类无法实例化对象
	Base* s = new Son;
	s->func();
}

int main() {
	test01();

	return 0;
}