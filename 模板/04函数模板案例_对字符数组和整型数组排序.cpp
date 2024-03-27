#include <iostream>
#include <algorithm>

template<typename T>
void Myprint(T arr[], int num) {
	for (int i = 0; i < num; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
template<typename T>
void MySort(T arr[], int num) {
	std::sort(arr, arr + num);
	
}

void test01() {
	char charArry[] = "adcvfes";
	MySort<char>(charArry, 7);
	Myprint<char>(charArry, 7);
}

void test02() {
	int intArry[] = { 6,1,5,3,4,2 };
	MySort<int>(intArry,6);
	Myprint<int>(intArry, 6);
}

int main() {
	test01();
	test02();
	return 0;
}