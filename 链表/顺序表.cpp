#include <iostream>
#define Size 5

typedef struct Node {
	int* e;
	int Length;
	int size;
}Node;

//��ʼ��
Node Init() {
	Node arr;
	arr.e = new int[Size];
	if (arr.e != nullptr) {
		arr.Length = Size;
		arr.size = 0;

		return arr;
	}
	else {
		std::cout << "��ʼ��ʧ��" << std::endl;
	}
}

//����Ԫ��
void add(Node& arr,int value) {
	if (arr.size == arr.Length) {
		std::cout << "˳���Ԫ��������" << std::endl;
		return;
	}
	arr.e[arr.size++] = value;
	std::cout << "��ӳɹ�" << std::endl;
}

//����Ԫ��ָ��λ��
int index(Node arr, int key) {
	int n = arr.size;
	for (int i = 0; i < n; i++) {
		if (arr.e[i] == key)
			return i;
	}
	return -1;
}

//ɾ��ָ��Ԫ��
void del(Node& arr, int value) {
	int k = index(arr, value);
	if (k == -1) {
		std::cout << "û�д�Ԫ��" << std::endl;
		return;
	}
	for (int i = k; i < arr.size; i++) {
		arr.e[i] = arr.e[i + 1];
	}
	arr.size--;
	std::cout << "ɾ���ɹ�" << std::endl;
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