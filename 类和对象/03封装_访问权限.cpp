#include <iostream>
using namespace std;

//访问权限
//公共权限 public  类内可以访问，类外可以访问
//私有权限 private 类内可以访问，类外不可以访问     子类可以继承父类的私有权限的成员
//保护权限 protected 类内可以访问，类外不可以访问   子类不可以继承父类保护权限的成员

class Person
{
//公共权限
public:
	string name = "张三";
//私有权限
private:
	string car = "比亚迪";
//保护权限
protected:
	int password = 123456;

public:
	//所有权限的成员在类内都可以访问，编译器不会报错
	void test() {
		name = "lina";
		car = "拖拉机";
		password = 11111;
	}
};


int main() {

	//实例化
	Person P1;
	
	P1.name = "李四"; //公共权限的成员类外可以访问、
	//P1.car = "奔驰";//私有权限的成员类外不可以访问
	//P1.password = 666666; //保护权限的成员类外不可以访问

	system("pause");
	return 0;
}