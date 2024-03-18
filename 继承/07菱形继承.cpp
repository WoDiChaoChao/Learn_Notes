#include <iostream>
using namespace std;

class Animal
{
public:
	int m_A;
};

//解决菱形继承的方法：在继承方式前加上virtual关键字
//使子类中继承的是虚类指针，根据偏移量来访问父类成员
//这样直接访问既不会产生异议，也不会造成资源浪费
class sheep : virtual public Animal
{
public:
	
};

class Tuo : virtual public Animal
{
public:
	
};

class sheepTuo : public sheep, public Tuo
{
public:
	
};

void test() {
	sheepTuo s;
	//菱形继承的问题：会产生异议，并且会造成资源浪费
	//在此例中，s访问的m_A在sheep中和在Tuo中都有，这样不仅直接访问会产生异议，还造成了资源浪费
	//s.m_A;

	
}

int main() {


	system("pause");
	return 0;
}