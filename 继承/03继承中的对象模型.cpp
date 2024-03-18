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

class base : public BasePage {
public:
	int m_D;
};

void test() {
	base b;
	//16 父类四个int 子类一个int
	//父类中的私有成员也会继承，但是访问不了
	cout << "size of b is " << sizeof(b) << endl;
}

int main() {

	test();

	system("pause");
	return 0;
}