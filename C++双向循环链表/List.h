#pragma once
#include <iostream>
using namespace std;

template <class T>
class ListNode
{
public:
	ListNode()
		:_data(0),
		 _prev(this),
		 _next(this)
	{}
	ListNode* BuyListNode(const T& x);
	void PushBack(const T& x);
	void PushFront(const T& x);
	void PopBack();
	void PopFront();
	ListNode* Find(const T& x);
	void Insert(ListNode* insert, const T& x);
	void Erase(ListNode* res);
	void Print();
	~ListNode()
	{}
private:
	T _data;
	ListNode* _prev;
	ListNode* _next;
};


template <class T>
ListNode<T>* ListNode<T>::BuyListNode(const T& x)
{
	ListNode<int>* newNode = new ListNode<int>;
	newNode->_data = x;
	newNode->_next = nullptr;
	newNode->_prev = nullptr;
	return newNode;
}

template <class T>
void ListNode<T>::PushBack(const T& x)
{
	ListNode<int>* newNode = BuyListNode(x);
	ListNode<int>* tail = this->_prev;
	tail->_next = newNode;
	this->_prev = newNode;
	newNode->_prev = tail;
	newNode->_next = this;
}

template <class T>
void ListNode<T>::PushFront(const T& x)
{
	ListNode<int>* newNode = BuyListNode(x);
	ListNode<int>* next = this->_next;
	newNode->_next = next;
	next->_prev = newNode;
	newNode->_prev = this;
	this->_next = newNode;
}

template <class T>
void ListNode<T>::PopBack()
{
	//ListNode<int>* tail = this->_prev;
	//this->_prev = tail->_prev;
	//tail->_prev->_next = this;
	//tail->~ListNode();
	
	ListNode<int>* tail = this->_prev;
	ListNode<int>* prev = tail->_prev;
	prev->_next = this;
	this->_prev = prev;
	delete tail;
}

template <class T>
void ListNode<T>::PopFront()
{
	ListNode<int>* next = this->_next;
	this->_next = next->_next;
	next->_next->_prev = this;
	delete next;
}

template <class T>
//注意！！！返回值如果是类的类型，那么也需要替换成 带<T>
//你可以这样理解： 真正的类名是 ListNode<T> 。 所有只要涉及使用类名的地方，就需要替换（函数体内不需要，函数形参也不需要）
ListNode<T>* ListNode<T>::Find(const T& x)
{
	ListNode<int>* cur = this->_next;
	while (cur != this)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return nullptr;
}

template <class T>
void ListNode<T>::Insert(ListNode* insert, const T& x)
{
	ListNode<int>* prev = insert->_prev;
	ListNode<int>* next = insert->_next;
	ListNode<int>* newNode = BuyListNode(x);
	prev->_next = newNode;
	next->_prev = newNode;
	newNode->_next = next;
	newNode->_prev = prev;
}

template <class T>
void ListNode<T>::Erase(ListNode* res)
{
	ListNode<int>* prev = res->_prev;
	ListNode<int>* next = res->_next;
	prev->_next = next;
	next->_prev = prev;
	delete res;
}

template <class T>
void ListNode<T>::Print()
{
	ListNode<int>* cur = this->_next;
	while (cur != this)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}