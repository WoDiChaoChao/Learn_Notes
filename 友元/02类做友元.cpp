#include <iostream>
using namespace std;

class Building
{
	friend class GoodGay;
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

class GoodGay
{
public:

	GoodGay();
	~GoodGay();

	void visit(); //好基友访问房子函数
	Building* build;

private:

protected:
};

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

void test() {
	GoodGay gg;
	gg.visit();
}

int main() {
	test();
	system("pause");
	return 0;
}