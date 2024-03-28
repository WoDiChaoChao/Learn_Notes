#include <iostream>
#define Size 5

typedef struct Node {
	int* e;
	int Length;
	int size;
}Node;

//初始化
Node Init() {
	Node arr;
	arr.e = new int[Size];
	if (arr.e != nullptr) {
		arr.Length = Size;
		arr.size = 0;

		return arr;
	}
	else {
		std::cout << "初始化失败" << std::endl;
	}
}

//增加元素
void add(Node& arr,int value) {
	if (arr.size == arr.Length) {
		std::cout << "顺序表元素已满！" << std::endl;
		return;
	}
	arr.e[arr.size++] = value;
	std::cout << "添加成功" << std::endl;
}

//查找元素指定位置
int index(Node arr, int key) {
	int n = arr.size;
	for (int i = 0; i < n; i++) {
		if (arr.e[i] == key)
			return i;
	}
	return -1;
}

//删除指定元素
void del(Node& arr, int value) {
	int k = index(arr, value);
	if (k == -1) {
		std::cout << "没有此元素" << std::endl;
		return;
	}
	for (int i = k; i < arr.size; i++) {
		arr.e[i] = arr.e[i + 1];
	}
	arr.size--;
	std::cout << "删除成功" << std::endl;
}

void show(Node arr) {
	int n = arr.size;
	for (int i = 0; i < n; i++) {
		std::cout << arr.e[i] << std::endl;
	}
}

int main() {
	Node a = Init();
	add(a, 1);
	add(a, 2);
	add(a, 3);
	add(a, 4);
	add(a, 5);
	add(a, 6);
	del(a, 6);
	del(a, 5);
	add(a, 6);
	show(a);

	return 0;
}