#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//堆的实现---数组
template <class T>
class Heap
{
public:
	void HeapCreate(T* a, int n);
	void Push(const T& x);
	void Pop();
	T Top();
	size_t Size();
	bool isEmpty();
	void Destory();
	void Print();

//private:
//	friend void <T>reserve();
	template <class T>
	friend void HeapSort(Heap<T>& hp);
private:
	T*     _a;
	size_t _size;
	size_t _capacity;
};

//template <class T>
//static void AdjustDown(T* a, int n, int parent)//这里的n不是_size，它是最后一个元素的下标 [当然也可以传参数时传_size，但是下面的代码要稍作修改...]
//{
//	int child = parent * 2 + 1;
//	while(child <= n)
//	{
//		//左孩子和右孩子进行比较，选出较小的【如果没有右孩子，不进行该比较】
//		if (child + 1 <= n && a[child] > a[child + 1])
//		{
//			++child;
//		}
//
//		//找左孩子和右孩子之中小的那个进行swap
//		if (a[parent] <= a[child])
//			break;
//		else// a[parent] > a[min]
//		{
//			swap(a[parent], a[child]);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//	}
//}

template <class T>
static void AdjustDown(T* a, int size, int parent)//n = _size
{
	//Left->child = 2 * parent + 1
	//Right->child = 2* parent + 2
	//parent = (child - 1) / 2

	int child = parent * 2 + 1;
	while (child < size)
	{
		//左孩子和右孩子进行比较，选出较小的【如果没有右孩子，不进行该比较】
		if (child + 1 < size && a[child] > a[child + 1])
		{
			++child;
		}

		//找左孩子和右孩子之中小的那个进行swap
		if (a[parent] <= a[child])
			break;
		else// a[parent] > a[min]
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}



//最小堆
template <class T>
void Heap<T>::HeapCreate(T* a, int n)
{
	T* tmp = new T[n];
	memcpy(tmp, a, sizeof(T)*n);
	_a = tmp;
	_size = _capacity = n;

	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		AdjustDown(_a, n - 1, i);
	}
}

//template <class T>
//void reserve()
//{
//	size_t newcapacity = _capacity *= 2;
//	T* tmp = new T[newcapacity];
//	memcpy(_a, tmp, sizeof(T) * newcapacity);
//	_capacity = newcapacity;
//}

//小堆
template <class T>
void AdjustUp(T* a, int child)
{
	while (child > 0)//child为0的时候，就说明他和parent一样了，都处于根节点。不用继续向上调整了
	{
		int parent = child / 2;
		if (a[parent] > a[child])
		{
			swap(a[parent], a[child]);
		}
		else
			break;
		child = parent;
	}
}

template <class T>
void Heap<T>::Push(const T& x)
{
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity *= 2;
		T* tmp = new T[newcapacity];
		memcpy(tmp, _a, sizeof(T) * newcapacity);
		_capacity = newcapacity;
		_a = tmp;
	}
	_a[_size++] = x;
	//向上调整
	AdjustUp(_a, _size - 1);
}

template <class T>
void Heap<T>::Pop()//Pop就是先将根节点与最后一个节点互换，然后进行1次向下调整即可
{
	swap(_a[0], _a[_size - 1]);
	--_size;
	AdjustDown(_a, _size - 1, 0);
}

template <class T>
T Heap<T>::Top()//返回堆顶元素
{
	assert(!isEmpty());
	return _a[0];
}

template <class T>
size_t Heap<T>::Size()
{
	return _size;
}

template <class T>
bool Heap<T>::isEmpty()
{
	return _size == 0 ? 1 : 0;
}

template <class T>
void Heap<T>::Destory()
{
	delete[] _a;
	_size = _capacity = 0;
}

template <class T>
void Heap<T>::Print()
{
	for (size_t i = 0; i < _size; ++i)
	{
		cout << _a[i] << " ";
	}
	cout << endl;
}

template <class T>
void HeapSort(Heap<T>& hp)// n = _size
{
	//小堆排	降序        大堆排 升序
	for (size_t i = hp._size - 1; i > 0; --i)
	{
		swap(hp._a[0], hp._a[i]);
		AdjustDown(hp._a, i, 0);
	}
}