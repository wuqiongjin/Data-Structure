#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//�ѵ�ʵ��---����
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
//static void AdjustDown(T* a, int n, int parent)//�����n����_size���������һ��Ԫ�ص��±� [��ȻҲ���Դ�����ʱ��_size����������Ĵ���Ҫ�����޸�...]
//{
//	int child = parent * 2 + 1;
//	while(child <= n)
//	{
//		//���Ӻ��Һ��ӽ��бȽϣ�ѡ����С�ġ����û���Һ��ӣ������иñȽϡ�
//		if (child + 1 <= n && a[child] > a[child + 1])
//		{
//			++child;
//		}
//
//		//�����Ӻ��Һ���֮��С���Ǹ�����swap
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
		//���Ӻ��Һ��ӽ��бȽϣ�ѡ����С�ġ����û���Һ��ӣ������иñȽϡ�
		if (child + 1 < size && a[child] > a[child + 1])
		{
			++child;
		}

		//�����Ӻ��Һ���֮��С���Ǹ�����swap
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



//��С��
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

//С��
template <class T>
void AdjustUp(T* a, int child)
{
	while (child > 0)//childΪ0��ʱ�򣬾�˵������parentһ���ˣ������ڸ��ڵ㡣���ü������ϵ�����
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
	//���ϵ���
	AdjustUp(_a, _size - 1);
}

template <class T>
void Heap<T>::Pop()//Pop�����Ƚ����ڵ������һ���ڵ㻥����Ȼ�����1�����µ�������
{
	swap(_a[0], _a[_size - 1]);
	--_size;
	AdjustDown(_a, _size - 1, 0);
}

template <class T>
T Heap<T>::Top()//���ضѶ�Ԫ��
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
	//С����	����        ����� ����
	for (size_t i = hp._size - 1; i > 0; --i)
	{
		swap(hp._a[0], hp._a[i]);
		AdjustDown(hp._a, i, 0);
	}
}