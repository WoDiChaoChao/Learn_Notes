#include <iostream>
using namespace std;

//继承方式
//public protected private

class BasePage
{
public:
	BasePage() {
		cout << "父类构造函数" << endl;
	}
	~BasePage() {
		cout << "父类析构函数" << endl;
	}
};

class base : public BasePage {
public:
	base() {
		cout << "子类构造函数" << endl;
	}

	~base() {
		cout << "子类析构函数" << endl;
	}

};

void test() {
	//构造先构造父类，在构造子类
	//析构先析构子类，再析构父类
	base b;
}

int main() {

	test();

	system("pause");
	return 0;
}