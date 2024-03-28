#pragma once
#include <iostream>

template<typename T>
class MyArray {
public:

	MyArray() {};

	//有参构造函数
	MyArray(int capacity) {
		//std::cout << "有参构造函数的调用" << std::endl;
		this->m_capacity = capacity;
		this->m_Size = 0;
		this->m_array = new T[this->m_capacity];
	}

	//拷贝构造函数
	MyArray(const MyArray& other) {
		//std::cout << "拷贝构造函数的调用" << std::endl;
		this->m_capacity = other.m_capacity;
		this->m_Size = other.m_Size;
		this->m_array = new T[other.m_capacity];

		for (int i = 0; i < this->m_capacity; i++) {
			this->m_array[i] = other.m_array[i];
		}
	}

	//拷贝赋值函数
	MyArray& operator=(const MyArray& other) {
		//std::cout << "拷贝赋值函数的调用" << std::endl;

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

	//尾插
	void Push_Back(T value) {
		if (this->m_capacity == this->m_Size) {
			return;
		}
		this->m_array[this->m_Size] = value;
		this->m_Size++;
	}
	//尾删
	void Pop_Back() {
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	
	//得到容量
	int get_Capacity() {
		return this->m_capacity;
	}

	//得到大小
	int get_Size() {
		return this->m_Size;
	}


	//重载[]运算符
	T& operator[](const int index) {
		return this->m_array[index];
	}

	//析构函数
	~MyArray() {
		//std::cout << "析构函数的调用" << std::endl;
		if (this->m_array != nullptr) {
			delete[] this->m_array;
			this->m_array = nullptr;
			this->m_capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T* m_array;//数组地址
	int m_capacity; //数组容量
	int m_Size; //数组大小
};