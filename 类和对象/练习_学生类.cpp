#include <iostream>
using namespace std;

class Student
{
public:
	//����
	int ID; //ѧ��
	string name; //����

	//��Ϊ
	void show() {
		cout << "ѧ�ţ�" << ID << endl << "������" << name<< endl;
	}

	//��������
	void setName(string str) {
		name = str;
	}

	//����ѧ��
	void setId(int id) {
		ID = id;
	}

private:

};

int main() {

	//ʵ����
	Student s1;
	//cin >> s1.ID >> s1.name;
	s1.setName("Lina");
	s1.setId(10);
	s1.show();


	system("pause");
	return 0;
}