#include <iostream>
using namespace std;

class Building
{
	friend class GoodGay;
public:
	Building();
	~Building();

	string sittingRoom; //����
private:
	string BedRoom; //����
protected:
	int money; //���չ�
};

Building::Building()
{
	this->sittingRoom = "����";
	this->BedRoom = "����";
	this->money = 1000; //���չ�
}

Building::~Building()
{
}

class GoodGay
{
public:

	GoodGay();
	~GoodGay();

	void visit(); //�û��ѷ��ʷ��Ӻ���
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
	cout << "�û������ڷ��ʣ�" << this->build->sittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << this->build->BedRoom << endl;
	cout << "�û������ڷ��ʣ�" << this->build->money << endl;
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