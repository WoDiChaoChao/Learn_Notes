#include <iostream>
using namespace std;

//分类
//有参构造函数 无参构造函数
//默认构造函数 拷贝构造函数

class Person
{
//分类
public:
	//无参构造函数(默认构造函数)
	Person() {
		cout << "Person 无参构造函数" << endl;
	}
	//有参构造函数(一般构造函数)
	Person(int a) {
		cout << "Person 有参构造函数" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		cout << "Person 拷贝构造函数" << endl;
	}
	//拷贝赋值函数
	Person& operator= (const Person& p) {
		if (p._data == this->_data)
			return *this;
		this->_data = p._data;
		cout << "Person 拷贝赋值" << endl;
		return *this;
	}
	//移动构造函数
	Person(Person&& other) {
		this->_data = other._data;
		cout << "Person 移动构造函数" << endl;
	}

	//移动赋值函数
	Person& operator=(Person&& other) {
		std::cout << "Person 移动赋值" << std::endl;
		this->_data = other._data;
		return *this;
	}

	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

	int _data;
private:
	
};

//调用
void test01() {
	//1.括号法
	//Person p1;	//无参/默认构造函数的调用
	//Person p2(10); //有参构造函数的调用
	//Person p3(p1); //拷贝构造函数的调用

	//2.显示法
	/*Person p2 = Person(10);
	Person p3 = Person(p2);*/

	//3.隐式转换法
	Person p1 = 10;
	Person p2 = p1;

	//4.调用赋值构造函数
	Person p3;
	p3._data = 10;
	Person p4;
	p4 = p3;
	cout << p4._data << endl;

	//5.调用移动构造函数
	Person p5;
	p5._data = 10;
	Person p6 = std::move(p5);
	cout << p6._data << endl;
}	

int main() {

	test01();

	system("pause");
	return 0;
}