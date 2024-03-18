#include <iostream>
using namespace std;

const double PI = 3.14;

//设计一个圆类，求圆的周长
class Circle
{
public:
	//属性
	int r;	//半径
	//行为
	double calculate(int r) {	//求周长
		return 2 * PI * r;
	}

private:

};

int main() {

	//实例化一个对象
	Circle C1;
	C1.r = 10;
	cout << "圆的周长为：" << C1.calculate(C1.r) << endl;

	system("pause");
	return 0;
}