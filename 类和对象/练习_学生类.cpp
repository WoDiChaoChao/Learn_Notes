#include <iostream>
using namespace std;

class Student
{
public:
	//属性
	int ID; //学号
	string name; //姓名

	//行为
	void show() {
		cout << "学号：" << ID << endl << "姓名：" << name<< endl;
	}

	//设置姓名
	void setName(string str) {
		name = str;
	}

	//设置学号
	void setId(int id) {
		ID = id;
	}

private:

};

int main() {

	//实例化
	Student s1;
	//cin >> s1.ID >> s1.name;
	s1.setName("Lina");
	s1.setId(10);
	s1.show();


	system("pause");
	return 0;
}