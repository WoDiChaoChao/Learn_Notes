#include <iostream>
using namespace std;

//全局函数做友元
class Building
{
	//在类内使用friend关键字定义全局函数，可以使全局函数访问私有成员和被保护成员
	friend void GoodGay(Building& build);
public:
	Building() {
		this->sittingRoom = "客厅";
		this->bedroom = "卧室";
		this->money = 10000;
	}

	string sittingRoom; //客厅
private:
	string bedroom; //卧室
protected:
	int money; //钱
};

void GoodGay(Building& build) {
	cout << "GoodGay全局函数正在访问：" << build.sittingRoom << endl;
	cout << "GoodGay全局函数正在访问：" << build.bedroom << endl;
	cout << "GoodGay全局函数正在访问：" << build.money << endl;
}

void test01() {
	Building build;
	GoodGay(build);
}
int main() {

	test01();
	system("pause");
	return 0;
}