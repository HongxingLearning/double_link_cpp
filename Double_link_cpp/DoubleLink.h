#pragma once
#ifndef DOUBLE_LINK_HONGXING
#define DOUBLE_LINK_HONGXING

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
template<class T>
struct DNode
{
public:
	T value;
	DNode *prev;
	DNode *next;
public:
	DNode() {}
	DNode(T t, DNode *prev, DNode *next)
	{
		this->value = t;
		this->next = next;
		this->prev = prev;
	}
};
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
template<class T>
class DoubleLink
{
public:

	int size();
	int is_empty();

	T get(int index);
	T get_first();
	T get_last();

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index, T t);
	int delete_first();
	int delete_last();

	DoubleLink();
	~DoubleLink();

private:
	int count;
	DNode<T> *phead;

private:
	DNode<T> *get_node(int index);
};

//���캯��
template<class T>
DoubleLink<T>::DoubleLink()
{
	//������ͷ(��)
	phead = new DNode<T>;
	phead->prev = phead->next = phead;
	count = 0;
}

//��������
template<class T>
DoubleLink<T>::~DoubleLink()
{
	//ɾ�����еĽڵ�
	DNode<T> ptmp;
	DNode<T> pnode = phead->next;

	while (pnode != phead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		delete ptmp;
	}

	//ɾ����ͷ
	delete phead;
	phead = NULL;
}
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////

//���ؽڵ���Ŀ
template<class T>
int DoubleLink<T>::size()
{
	return count;
}

//�Ƿ�Ϊ��
template<class T>
int DoubleLink<T>::is_empty()
{
	return count == 0;
}

//��ȡ��indexλ�õĽڵ�
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	//�жϲ���
	if (index < 0 || index >= count)
	{
		cout << "get node failed! the index is out of bound!" << endl;
		return NULL;
	}

	//�������
	if (index <= count / 2)
	{
		DNode<T>*pindex = phead->next;
		int i = 0;
		while (i++ < index)
			pindex = pindex->next;
		return pindex;
	}

	int j = 0;
	int prindex = count - index - 1;
	DNode<T>*prindex = phead->prev;
	while (j++ < prindex)
		prindex = prindex->prev;

	return prindex;
}

//��ȡ��indexλ�õ�ֵ
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}

//��ȡ��һ���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}

//��ȡ���һ���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_last()
{
	return get_node(count - 1)->value;
}

//���ڵ���뵽indexλ��֮ǰ
template<class T>
int DoubleLink<T>::insert(int index, T t)
{
	if (index == 0)
		insert_first(t);

	DNode<T> *pindex = get_node(index);
	DNode<T> *pnode = new DNode<T>(t, pindex->prev, pindex);

	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;
	return 0;
}

//���ڵ���뵽��һ���ڵ㴦
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T> *pnode = new DNode<T>(t, phead, phead->next);
	phead->next = pnode;
	phead->next->prev = pnode;
	count++;
	return 0;
}

//���ڵ���뵽����ĩβ
template<class T>
int DoubleLink<T>::append_last(T t)
{
	DNode<T> *pnode = new DNode<T>(t, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;
	return 0;
}

//ɾ��indexλ�õĽڵ�
template<class T>
int DoubleLink<T>::del(int index, T t)
{
	DNode<T> *pindex = get_node(index);
	pindex->prev->next = pindex->next;
	pindex->next->prev = pindex->prev;
	delete pindex;
	count--;
	return 0;
}

//ɾ����һ���ڵ�
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}

//ɾ�����һ��Ԫ��
template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count - 1);
}
//////////////////////////////////////////////////////////////////////////
#endif