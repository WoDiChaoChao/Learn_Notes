#include <iostream>
using namespace std;
class Person
{
public:
	//1.构造函数
	//函数名和类名一样，没有返回值
	//构造函数可以有参数，可以发生函数重载
	//实例化对象的时候，会自动调用构造函数，并且只调用一次
	Person() {
		cout << "Person 构造函数的调用" << endl;
	}

	//2.析构函数
	//函数名和类名一样，前面加个~，没有返回值
	//析构函数不可以有参数，不可以发生重载
	//在销毁对象之前会自动调用，并且只调用一次
	~Person() {
		cout << "Person 析构函数的调用" << endl;
	}

private:

};

void test() {
	Person P;	//内存开辟在栈上，函数调用完系统自动释放内存，在释放之前调用析构函数
}

int main() {

	//test();

	Person p;

	system("pause");
	return 0;
}