#include <iostream>
using namespace std;

class Building;

class GoodGay
{
public:

	GoodGay();
	~GoodGay();

	void visit(); //好基友访问房子函数
	void visit2(); //不可以访问房子的私有属性
	Building* build;

private:

protected:
};



class Building
{
	friend void GoodGay::visit();
public:
	Building();
	~Building();

	string sittingRoom; //客厅
private:
	string BedRoom; //卧室
protected:
	int money; //保险柜
};

Building::Building()
{
	this->sittingRoom = "客厅";
	this->BedRoom = "卧室";
	this->money = 1000; //保险柜
}

Building::~Building()
{
}

GoodGay::GoodGay()
{
	build = new Building;
}

GoodGay::~GoodGay()
{
	delete build;
}

void GoodGay::visit() {
	cout << "好基友正在访问：" << this->build->sittingRoom << endl;
	cout << "好基友正在访问：" << this->build->BedRoom << endl;
	cout << "好基友正在访问：" << this->build->money << endl;
}

void GoodGay::visit2() {
	cout << "好基友正在访问：" << this->build->sittingRoom << endl;
	//cout << "好基友正在访问：" << this->build->BedRoom << endl;
	//cout << "好基友正在访问：" << this->build->money << endl;
}

void test() {
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main() {
	test();
	system("pause");
	return 0;
}