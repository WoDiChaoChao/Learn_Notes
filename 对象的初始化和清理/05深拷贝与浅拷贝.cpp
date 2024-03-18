#include <iostream>
using namespace std;

//浅拷贝：编译器默认的拷贝构造函数里的等号赋值操作
//深拷贝：自己编写拷贝构造函数来在堆区开辟空间进行赋值

class Person
{
public:
	Person() {
		cout << "Person 默认构造函数调用" << endl;
	}
	Person(int age, int H) {
		m_Age = age;
		m_H = new int(H);
		cout << "Person 有参构造函数" << endl;
	}

	Person(const Person& p) {
		m_Age = p.m_Age;
		//m_H = p.m_H; //编译器默认的拷贝就是浅拷贝，直接等号赋值，但这样在析构的时候会造成内存重复释放的问题
		m_H = new int(*p.m_H);	//在拷贝的时候，对于堆区的成员属性重新在堆区开辟一块空间进行赋值，这就是深拷贝
		cout << "Person 拷贝函数的调用" << endl;
	}

	~Person() {
		//析构函数一般用来释放内存开辟在堆区的成员属性
		if (m_H != NULL) {
			delete m_H;
			m_H = NULL;
		}
		cout << "Person 析构函数调用" << endl;
	}

	int m_Age;
	int* m_H;

private:

};

void test() {
	Person p1(18,160);
	cout << "p1年龄：" << p1.m_Age << "  身高：" << *p1.m_H << endl;

	Person p2(p1);
	cout << "p2年龄：" << p2.m_Age << "  身高：" << *p2.m_H << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}