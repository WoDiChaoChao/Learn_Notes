#include <iostream>
using namespace std;

class Building;

class GoodGay
{
public:

	GoodGay();
	~GoodGay();

	void visit(); //�û��ѷ��ʷ��Ӻ���
	void visit2(); //�����Է��ʷ��ӵ�˽������
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

void GoodGay::visit2() {
	cout << "�û������ڷ��ʣ�" << this->build->sittingRoom << endl;
	//cout << "�û������ڷ��ʣ�" << this->build->BedRoom << endl;
	//cout << "�û������ڷ��ʣ�" << this->build->money << endl;
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