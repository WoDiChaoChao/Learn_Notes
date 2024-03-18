#include <iostream>
using namespace std;

int* func() {

	int* a = new int(10);
	return a;

}

int main() {

	//堆区生成于程序执行之后
	//堆区由程序员自己进行内存的开辟和释放，若有内存没有释放，编译器会在程序结束之后自动释放
	//堆区的内存由关键词 new开辟  delete释放

	int* p = func();
	cout << *p << endl;
	int b;
	cin >> b;
	cout << *p << endl;	//这里局部变量a存放的是堆区的内存，在函数执行完成后，存放变量a的地址被释放，但在a地址被释放前，已经将堆区的地址返回给p了

	system("pause");
	return 0;
}