#include <iostream>
using namespace std;

//设计一个立方体类
//设计成员函数求立方体的体积和面积
//利用全局函数和成员函数来判断两个立方体是否相等

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

	//利用成员函数判断两个立方体是否相同
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

//利用全局函数判断立方体是否相同
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
	cout << "C1的表面积：" << C1.calculateS() << endl;
	cout << "C1的体积：" << C1.calculateV() << endl;

	Cube C2;
	C2.setL(10);
	C2.setW(10);
	C2.setH(10);
	cout << "C2的表面积：" << C2.calculateS() << endl;
	cout << "C2的体积：" << C2.calculateV() << endl;

	bool ret = isSame(C1, C2);
	if (ret) {
		cout << "C1和C2相同" << endl;
	}
	else {
		cout << "C1和C2不相同" << endl;
	}

	ret = C1.isSameByclass(C2);
	if (ret) {
		cout << "成员函数：C1和C2相同" << endl;
	}
	else {
		cout << "成员函数：C1和C2不相同" << endl;
	}

	system("pause");
	return 0;
}