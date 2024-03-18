#include <iostream>
using namespace std;

//一般都会将成员属性设置为私有，然后通过公共的成员函数来对成员属性进行读写的操作
//优点1：可以自己控制成员属性的读写操作
//优点2：可以检测成员属性的有效性

class Person
{
public:
	//设置姓名
	void setName(string str) {
		m_Name = str;
	}
	//获取姓名
	string getName() {
		return m_Name;
	}
	//设置年龄
	void setAge(int age) {
		m_Age = 0;
		if (age < 0 || age>100) {
			cout << "年龄有误！" << endl;
			return;
		}
		m_Age = age;
	}
	//获取年龄
	int getAge() {
		return m_Age;
	}
	//设置情人
	void setLover(string str) {
		m_Lover = str;
	}

	void show() {
		cout << "姓名：" << m_Name << endl << "年龄：" << m_Age << endl << "情人：" << m_Lover << endl;
	}

private:
	string m_Name;//姓名 可读可写
	int m_Age; //年龄 可读可写，写入时检测有效性(0-100)
	string m_Lover; //情人 可写
};


int main() {

	Person P1;
	P1.setName("张三");
	cout << "姓名：" << P1.getName() << endl;
	P1.setAge(10);
	cout << "年龄：" << P1.getAge() << endl;
	P1.setLover("苍劲");


	system("pause");
	return 0;
}