#pragma once
#include <iostream>

template<typename T>
class MyArray {
public:

	MyArray() {};

	//�вι��캯��
	MyArray(int capacity) {
		//std::cout << "�вι��캯���ĵ���" << std::endl;
		this->m_capacity = capacity;
		this->m_Size = 0;
		this->m_array = new T[this->m_capacity];
	}

	//�������캯��
	MyArray(const MyArray& other) {
		//std::cout << "�������캯���ĵ���" << std::endl;
		this->m_capacity = other.m_capacity;
		this->m_Size = other.m_Size;
		this->m_array = new T[other.m_capacity];

		for (int i = 0; i < this->m_capacity; i++) {
			this->m_array[i] = other.m_array[i];
		}
	}

	//������ֵ����
	MyArray& operator=(const MyArray& other) {
		//std::cout << "������ֵ�����ĵ���" << std::endl;

		if (this->m_array != nullptr) {
			delete[] this->m_array;
			this->m_array = nullptr;
			this->m_capacity = 0;
			this->m_Size = 0;
		}

		this->m_capacity = other.m_capacity;
		this->m_Size = other.m_Size;
		this->m_array = new T[other.m_capacity];

		for (int i = 0; i < this->m_capacity; i++) {
			this->m_array[i] = other.m_array[i];
		}
		return *this;
	}

	//β��
	void Push_Back(T value) {
		if (this->m_capacity == this->m_Size) {
			return;
		}
		this->m_array[this->m_Size] = value;
		this->m_Size++;
	}
	//βɾ
	void Pop_Back() {
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	
	//�õ�����
	int get_Capacity() {
		return this->m_capacity;
	}

	//�õ���С
	int get_Size() {
		return this->m_Size;
	}


	//����[]�����
	T& operator[](const int index) {
		return this->m_array[index];
	}

	//��������
	~MyArray() {
		//std::cout << "���������ĵ���" << std::endl;
		if (this->m_array != nullptr) {
			delete[] this->m_array;
			this->m_array = nullptr;
			this->m_capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T* m_array;//�����ַ
	int m_capacity; //��������
	int m_Size; //�����С
};