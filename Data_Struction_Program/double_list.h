#include<iostream>
#ifndef DOUBLE_LIST_HXX
#define DOUBLE_LIST_HXX
using namespace std;

// ��ģ�壺���������г�Ա���������ͣ�ʹ����ʹ���п������⻯���ݽṹ������
template <typename T>class DNode {
public:
	T value; //�ڵ㴢�������
	DNode *prev;	//ǰָ��
	DNode *next;	//��ָ��
public:
	DNode() {};//Ĭ�Ϲ���ڵ�
	DNode(T v, DNode* prev, DNode* next) {
		this->value = v;
		this->prev = prev;
		this->next = next;
	}							//�вι���ڵ�
};

template <typename T>class DLink {
private:
	int count;			//��¼�б���
	DNode<T>* phead;	//ͷ�ڵ�
public:
	DLink() {
		//������ͷ����һ��ͷ�ڵ㣬����������
		phead = new DNode<T>();
		phead->prev = phead->next = phead;	//ǰָ��ͺ�ָ�붼ָ�ڵ�һ���ڵ�
		count = 0;
	};
	~DLink() {
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
	};

	int size() { return count; };			//��ȡ��С
	bool is_empty() { return count == 0; };		//�ж��Ƿ�Ϊ���б�

	T get(int index) {
		return getNode(index)->value;
	};
	T get_first() {
		return getNode(0)->value;
	};
	T get_last() { 
		return getNode(count - 1)->value;
	};

	int insert(T t, int index) {
		if (count == 0) {
			return insert_first(t);
		}
		DNode<int>* pindex = getNode(index);
		DNode<int>* pnode = new DNode<int>(t, pindex->prev, pindex);
		//new����callconstructor������
		pindex->prev->next = pnode;
		pindex->prev = pnode;
		count++;
		return 0;
	};
	int insert_first(T t) {
		DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
		phead->next->prev = pnode;
		phead->next = pnode;
		count++;
		return 0;
	};
	int insert_last(T t) {
		DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
		phead->prev->next = pnode;
		phead->prev = pnode;
		count++;
		return 0;
	};

	
	int del(int index) {
		DNode<T>* pindex = getNode(index);
		pindex->prev->next = pindex->next;
		pindex->next->prev = pindex->prev;
		delete pindex;									//delete���ͷ�ָ��ָ����ڴ�
		count--;
		return 0;
	};	//remove
	int delete_first() {
		del(0);
		count--;
		return 0;
	};
	int delete_last() {
		del(count - 1);
	};
private:
	DNode<T>* getNode(int index) {
		//�ж����������Ч�ԣ���߳���Ľ�׳��
		if (index<0 || index>=count) {
			cout << "get node failed1" << endl;
			return NULL;
		}

		//�������
		if (index <= count / 2) {
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
	};
};






#endif // !DOUBLE_LIST_HXX



