#include <iostream>
using namespace std;

//const修饰成员函数

class Person
{
public:
	
	//在普通函数下可以修改成员属性的值
	void func1() {
		m_A = 100;
	}

	//const修饰的函数不可以修改成员属性的值
	//每个成员函数中都会默认带有this指针
	//常函数
	void func2()const {
		
		//this指针本质上是一个指针常量 Person * const this; 不可以更改this指针的指向
		//this = nullptr;
		//const修饰成员函数 本质上是 const Person* const this; 不可以更改this指针指向对象的值
		//this->m_A = 100;

		m_B = 100;
	}

	int m_A;
	mutable int m_B; //加入mutable关键字可以在常函数里修改成员属性的值
private:

};

//常对象
void test() {
	const Person p1;
	//p1.m_A = 100; //常对象也不可以修改成员属性，
	//原因是因为 p1是this指针指向的内容，前面加上const,const Person* const this;不可以更改this指针指向对象的值

	p1.m_B = 100;//加入mutable关键字可以在常对象里修改成员属性的值

	//常对象只能调用常函数
	//p1.func1();
	p1.func2();  
}

int main() {


	system("pause");
	return 0;
}