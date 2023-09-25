#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include "double_list.h"
using namespace std;

//C++ʵ��˫������

//���캯��
template <typename T>DLink<T>::DLink() {
	//������ͷ����һ��ͷ�ڵ㣬����������
	phead = new DNode<T>();
	phead->prev = phead->next = phead;	//ǰָ��ͺ�ָ�붼ָ�ڵ�һ���ڵ�
	count = 0;

}

template <typename T>DLink<T>::~DLink() {
	//ɾ�����нڵ�
	DNode<T>* ptmp;
	DNode<T>* pnode = phead->next;
	while (pnode != phead) {
		ptmp = pnode;
		pnode->next = pnode;
		delete ptmp;

	}

	//ɾ����ͷ
	delete phead;
	phead = NULL;
}


//���������С
template <typename T>int DLink<T>::size() {
	return count;
}

//�ж������Ƿ�Ϊ��
template <typename T>bool DLink<T>::is_empty() {
	if (count ==0){
		return true;
	}
	else {
		return false;
	}
}

//��ȡ��indexλ�õĽڵ�,����һ��ָ��ýڵ��ָ��
template <typename T>DNode<T>* DLink<T>::getNode(int index) {
	//�ж����������Ч�ԣ���߳���Ľ�׳��
	if (index<0 || index>count) {
		cout << "get node failed1" << endl;
		return NULL;
	}

	//�������
	if (index <= count/2) {
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {
			pindex = pindex->next;

		}
		return pindex;

	}
	//�������
	if (index > count / 2) {
		int j = 0;
		int rindex = count - index - 1;
		DNode<T>* pindex = phead->prev;	//ע���ͷ��ǰָ��ָ���Ԫ�������һ��Ԫ��
		while (j++ < rindex) {
			pindex = pindex->prev;
								//˫�����ʹʱ�临�Ӷ��½�
		}
		return pindex;
	}
}

//��ȡindex�ڵ��ֵ
template <typename T>T DLink<T>::get(int index) {
	return getNode(index)->value;
}


//��ȡ��һ���ڵ�ֵ
template <typename T>T DLink<T>::get_first() {
	return phead->next->value;
}

//��ȡ���һ���ڵ��ֵ
template <typename T>T DLink<T>::get_last() {
	return phead->prev->value;
}

//���ڵ���뵽��indexλ��֮ǰ
template <typename T>int DLink<T>::insert(T data, int index) {
	if (count = 0) return insert_first(data);
	DNode<int>* pindex = getNode(index);
	DNode<int>* pnode = new DNode<int>(data, pindex->prev, pindex);
	//new����callconstructor������
	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;
	return 0;
}

//���ڵ���뵽��һ���ڵ㴦
template <typename T>int DLink<T>::insert_first(T data) {
	DNode<T>* pnode = new DNode<T>(data, phead, phead->next);
	phead->next = pnode;
	phead->next->prev = pnode;
	count++;
	return 0;
}

//���ڵ���뵽���һ��λ��
template <typename T>int DLink<T>::insert_last(T data) {
	DNode<T>* pnode = new DNode<T>(data, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;
	return 0;
}

//ɾ��indexλ�õĽڵ�
template <typename T>int DLink<T>::del(int index) {
	DNode<T>* pindex = getNode(index);
	pindex->prev->next = pindex->next;
	pindex->next->prev = pindex->prev;
	delete pindex;									//delete���ͷ�ָ��ָ����ڴ�
	count--;
	return 0;

}

//ɾ����һ��Ԫ��
template <typename T>int DLink<T>::delete_first() {
	del(1);
	count--;
	return 0;
}

//ɾ�����һ��Ԫ��
template <typename T>
int DLink<T>::delete_last() {
	del(count - 1);							//ע�������count���߼������������������
}

//test

int main() {
	DLink<int> link;
	link = DLink<int>::DLink();
	link.insert_first(1);
	link.get_first();

	return 0;
}

















































