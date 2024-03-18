#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 10;

static int s_g_a = 10;
static int s_g_b = 10;

const int c_g_a = 10;

int main() {

	//全局区生成于程序执行之前
	//全局区存放 全局变量，静态变量，常量

	int a = 10;
	cout << "局部变量 a 的地址为：" << (int)&a << endl;

	//1.全局变量
	cout << "全局变量 g_a 的地址为：" << (int)&g_a << endl;
	cout << "全局变量 g_b 的地址为：" << (int)&g_b << endl;

	//2.静态局部变量
	static int s_l_a = 10;
	static int s_l_b = 10;
	cout << "静态局部变量 s_l_a 的地址为：" << (int)&s_l_a << endl;
	cout << "静态局部变量 s_l_b 的地址为：" << (int)&s_l_b << endl;

	//3.静态全局变量
	cout << "静态全局变量 s_g_a 的地址为：" << (int)&s_g_a << endl;
	cout << "静态全局变量 s_g_b 的地址为：" << (int)&s_g_b << endl;

	//4.常量（字符串常量和const修饰的全局变量，也叫全局常量）
	cout << "字符串常量的地址为：" << (int)&"hello world" << endl;
	cout << "const修饰的全局变量 c_g_a 的地址为：" << (int)&c_g_a << endl;

	const int c_l_a = 10;
	cout << "const修饰的局部变量 c_l_a 的地址为：" << (int)&c_l_a << endl;

	system("pause");
	return 0;
}