 #define _CRT_SECURE_NO_WARNINGS 1
#ifndef STACK_ARR_HXX
#define STACK_ARR_HXX

#include<iostream>
using namespace std;

template<typename T>class stackArr {
public:
	//Ĭ�ϴ�С20
	stackArr() {
		arr = new T[20];
		count = 0;
		if (!arr) {
			cout << "arr malloc false!" << endl;
		}
		
	}

	//����
	~stackArr() {
		if (arr) {
			delete[] arr;
			arr = NULL;
		}
		cout << "xiaohui success!" << endl;
	}

	//���t��ջ��
	void push(T t) {
		arr[count++] = t;
	
	};

	//����ջ��Ԫ��ֵ
	T peek() {
		return arr[count - 1];
	};

	//ɾ��ջ��Ԫ�ز�����
	T pop() {
		int ret = arr[count - 1];
		count--;
		return ret;
	};

	int size() {
		return count;
	};
	int isEmpty() {
		
	};
private:
	T* arr;
	int count;
};





#endif // !STACK_ARR_HXX
