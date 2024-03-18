#include <iostream>
using namespace std;

//继承方式
//public protected private

class BasePage
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公共继承
class Son1 :public BasePage {
public:
	void func() {
		m_A = 100; //公共继承，父类公共成员变为子类的公共成员
		m_B = 100; //公共继承，父类保护成员变为子类的保护成员
		//m_C = 100; //公共继承，父类的私有成员不可以访问
	}
};

//保护继承
class Son2 :protected BasePage {
public:
	void func() {
		m_A = 100; //保护继承，父类公共成员变为子类的保护成员
		m_B = 100; //保护继承，父类保护成员变为子类的保护成员
		//m_C = 100; //保护继承，父类的私有成员不可以访问
	}
};

//私有继承
class Son3 :private BasePage {
public:
	void func() {
		m_A = 100; //私有继承，父类公共成员变为子类的私有成员
		m_B = 100; //私有继承，父类保护成员变为子类的私有成员
		//m_C = 100; //私有继承，父类的私有成员不可以访问
	}
};

//保护继承测试代码
void test02() {
	Son2 s1;
	//s1.m_A = 100;  ////保护继承，父类公共成员变为子类的保护成员
	//s1.m_B = 100; ////保护继承，父类保护成员变为子类的保护成员
}

//公共继承测试代码
void test01() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; ////公共继承，父类保护成员变为子类的保护成员
}

//私有继承测试代码
void test03() {
	Son3 s1;
	//s1.m_A = 100;//私有继承，父类保护成员变为子类的私有成员
	//s1.m_B = 100; ////私有继承，父类保护成员变为子类的私有成员
}

int main() {

	test();

	system("pause");
	return 0;
}