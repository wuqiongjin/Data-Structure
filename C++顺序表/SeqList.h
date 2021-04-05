#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

typedef int SLDataType;

class SeqList
{
public:
	SeqList()
	{
		_a = nullptr;
		_size = _capacity = 0;
	}

	~SeqList()
	{
		free(_a);
		_a = nullptr;
		_capacity = _size = 0;
	}
	void PushBack(SeqList* ps, SLDataType x);
	void PushFront(SeqList* ps, SLDataType x);
	void PopBack(SeqList* ps);
	void PopFront(SeqList* ps);

	int Find(SeqList* ps, SLDataType x);
	void Insert(SeqList* ps, size_t pos, SLDataType x);
	void Erase(SeqList* ps, size_t pos);

	void Print(SeqList* ps);
	void CheckCapacity(SeqList* ps);
private:
	SLDataType* _a;
	size_t		_size;
	size_t		_capacity;
};