#include <iostream>
using namespace std;

//���һ����������
//��Ƴ�Ա���������������������
//����ȫ�ֺ����ͳ�Ա�������ж������������Ƿ����

class Cube {

public:

	void setL(int l) {
		m_L = l;
	}
	int getL() {
		return m_L;
	}

	void setW(int w) {
		m_W = w;
	}
	int getW() {
		return m_W;
	}

	void setH(int h) {
		m_H = h;
	}
	int getH() {
		return m_H;
	}

	int calculateV() {
		return m_L * m_W * m_H;
	}
	int calculateS() {
		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
	}

	//���ó�Ա�����ж������������Ƿ���ͬ
	bool isSameByclass(Cube& c) {
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH()) {
			return true;
		}
		return false;
	}

private:
	int m_L;
	int m_W;
	int m_H;

};

//����ȫ�ֺ����ж��������Ƿ���ͬ
bool isSame(Cube& c1, Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}

int main() {

	Cube C1;
	C1.setL(10);
	C1.setW(10);
	C1.setH(10);
	cout << "C1�ı������" << C1.calculateS() << endl;
	cout << "C1�������" << C1.calculateV() << endl;

	Cube C2;
	C2.setL(10);
	C2.setW(10);
	C2.setH(10);
	cout << "C2�ı������" << C2.calculateS() << endl;
	cout << "C2�������" << C2.calculateV() << endl;

	bool ret = isSame(C1, C2);
	if (ret) {
		cout << "C1��C2��ͬ" << endl;
	}
	else {
		cout << "C1��C2����ͬ" << endl;
	}

	ret = C1.isSameByclass(C2);
	if (ret) {
		cout << "��Ա������C1��C2��ͬ" << endl;
	}
	else {
		cout << "��Ա������C1��C2����ͬ" << endl;
	}

	system("pause");
	return 0;
}