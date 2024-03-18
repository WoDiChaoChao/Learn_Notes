/*
多态分为两类：
	静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
	动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：
	静态多态的函数地址早绑定 - 编译阶段确定函数地址
	动态多态的函数地址晚绑定 - 运行阶段确定函数地址

动态多态的满足条件：
	具有继承关系
	子类重写父类的虚函数  重写：函数名 返回值 形参列表都一一相同
动态多态的使用：父类的指针或引用指向子类的对象

多态原理：子类对父类虚函数的重写，覆盖了子类中的虚函数表，把里面的函数地址修改为自己的

*/

#include <iostream>
using namespace std;

//动物类
class  Animal
{
public:
	//虚函数
	virtual void speak() {
		cout << "动物在说话" << endl;
	}

private:

};

class Cat : public Animal
{
	void speak() {
		cout << "小猫在说话" << endl;
	}

};
//父类中和子类同名的函数没有加virtual关键字	地址早绑定，编译阶段就绑定
//父类中和子类同名的函数加上virtual关键字	地址晚绑定，运行阶段绑定
void doSpeak(Animal& animal) {	//Animal& animal = cat
	animal.speak();
}

void test01() {
	Cat cat;
	doSpeak(cat);
}

int main() {
	test01();
	return 0;
}
