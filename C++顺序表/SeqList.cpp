#include "SeqList.h"

void SeqList::CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		size_t newCapacity = ps->_capacity == 0 ? 3 : 2 * ps->_capacity;
		ps->_a = (SLDataType*)realloc(ps->_a, sizeof(SLDataType)*newCapacity);
		ps->_capacity = newCapacity;
	}
}

void SeqList::PushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_size++] = x;
}

void SeqList::PushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	
	for (size_t i = ps->_size; i > 0; --i)
	{
		ps->_a[i] = ps->_a[i - 1];
	}
	ps->_a[0] = x;
	ps->_size++;
}

void SeqList::PopBack(SeqList* ps)
{
	assert(ps);
	if(ps->_size)
		ps->_a[ps->_size--];
}

void SeqList::PopFront(SeqList* ps)
{
	assert(ps);
	if (ps->_size)
	{
		for (size_t i = 0; i < ps->_size - 1; ++i)
		{
			ps->_a[i] = ps->_a[i + 1];
		}
		ps->_size--;
	}
}

int SeqList::Find(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->_size; ++i)
	{
		if (ps->_a[i] == x)
			return i;
	}
	return -1;
}

void SeqList::Insert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (size_t i = ps->_size; i > pos; --i)
	{
		ps->_a[i] = ps->_a[i - 1];
	}
	ps->_a[pos] = x;
	ps->_size++;
}

void SeqList::Erase(SeqList* ps, size_t pos)
{
	assert(ps);
	for (size_t i = pos; i < ps->_size - 1; ++i)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->_size--;
}

void SeqList::Print(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		//cout << ps->_a[i] << " ";
		cout << ps->_a[i] << " ";
	}
	cout << endl;
}

//
//void SeqList::SeqListDestory(SeqList* ps)
//{
//	assert(ps);
//	free(ps->_a);
//	ps->_capacity = ps->_size = 0;
//	free(ps);
//	ps = nullptr;
//}