#include <iostream>
using namespace std;

const double PI = 3.14;

//���һ��Բ�࣬��Բ���ܳ�
class Circle
{
public:
	//����
	int r;	//�뾶
	//��Ϊ
	double calculate(int r) {	//���ܳ�
		return 2 * PI * r;
	}

private:

};

int main() {

	//ʵ����һ������
	Circle C1;
	C1.r = 10;
	cout << "Բ���ܳ�Ϊ��" << C1.calculate(C1.r) << endl;

	system("pause");
	return 0;
}