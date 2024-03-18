/*

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放的时候无法调用子类的析构函数
如何解决：把父类的析构函数写成虚析构函数或纯虚析构函数，
注意
	虚析构函数和纯虚析构函数都需要写实现，不能只写声明
	如果写了纯虚析构函数，那么这个类也就成了抽象类
*/
#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	//把父类的析构函数写成虚析构函数
	//virtual ~Animal();
	//把父类的析构函数写成纯虚析构函数
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};

Animal::Animal() {
	cout << "Animal构造函数" << endl;

}

Animal::~Animal() {
	cout << "Animal析构函数调用" << endl;
}

class Cat :public Animal {
public:
	Cat(string name);
	~Cat();
	virtual void speak() {
		cout << *m_name<<"小猫在说话" << endl;
	}

	string* m_name;
};

Cat::Cat(string name) {
	cout << "Cat构造函数的使用" << endl;
	m_name = new string(name);
}
Cat::~Cat() {
	if (m_name != NULL) {
		cout << "Cat析构函数调用" << endl;
		delete m_name;
	}
}

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在释放的时候无法调用子类的析构函数
	delete animal;
}

int main() {
	test01();
	return 0;
}