#include <iostream>
using namespace std;

//ȫ�ֺ�������Ԫ
class Building
{
	//������ʹ��friend�ؼ��ֶ���ȫ�ֺ���������ʹȫ�ֺ�������˽�г�Ա�ͱ�������Ա
	friend void GoodGay(Building& build);
public:
	Building() {
		this->sittingRoom = "����";
		this->bedroom = "����";
		this->money = 10000;
	}

	string sittingRoom; //����
private:
	string bedroom; //����
protected:
	int money; //Ǯ
};

void GoodGay(Building& build) {
	cout << "GoodGayȫ�ֺ������ڷ��ʣ�" << build.sittingRoom << endl;
	cout << "GoodGayȫ�ֺ������ڷ��ʣ�" << build.bedroom << endl;
	cout << "GoodGayȫ�ֺ������ڷ��ʣ�" << build.money << endl;
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