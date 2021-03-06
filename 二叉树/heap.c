#include "heap.h"

//向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		//左孩子和右孩子进行比较，选出较小的【如果没有右孩子，不进行该比较】
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		//判断孩子节点和父节点【调成小堆】
		if (a[child] < a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = 2 * child + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapCreate(Heap* hp, HpDataType* a, int sz)
{
	//堆的空间开辟和初始化
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*sz);
	hp->_size = sz;
	hp->_capacity = sz;
	//数据的拷贝
	memcpy(hp->_a, a, sizeof(HpDataType)*sz);

	//堆的创建
	int i = 0;
	for (i = (sz - 1 - 1) / 2;i >= 0;--i)
	{
		AdjustDown(hp->_a, sz, i);
	}
}

void HeapPush(Heap* hp, HpDataType x)
{
	//增容操作
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = 2 * hp->_capacity;
		hp->_a = realloc(hp->_a, sizeof(HpDataType)*newCapacity);
		hp->_capacity = newCapacity;
	}

	//向堆中插入元素
	hp->_a[hp->_size] = x;
	hp->_size++;

	//向上调整算法
	AdjustUp(hp->_a, hp->_size - 1);
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(int* a, int child)
{
	while (child > 0)
	{
		int parent = (child - 1) / 2;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
	}
}

void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0;i < hp->_size;++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

void HeapSort(Heap* hp)
{
	int i = 0;
	for (i = hp->_size - 1; i > 0;--i)
	{
		Swap(&hp->_a[i], &hp->_a[0]);
		AdjustDown(hp->_a, i, 0);
	}
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

HpDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void PrintTopK(int* a, int n, int K)
{
	Heap hp;
	HeapCreate(&hp, a, K);

	int i = 0;
	for (i = K; i < n; ++i)
	{
		if (a[i] > HeapTop(&hp))
		{
			hp._a[0] = a[i];
 			AdjustDown(hp._a, K, 0);
		}
	}
	for (i = 0; i < K;++i)
	{
		printf("%d ", hp._a[i]);
	}
}


void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand((size_t)time(0));
	int i = 0;
	for (i = 0;i < n;++i)
	{
		a[i] = rand() % 1000000;
	}

	a[10] = 1000000 + 1;
	a[11] = 1000000 + 2;
	a[48] = 1000000 + 3;
	a[110] = 1000000 + 4;
	a[219] = 1000000 + 5;
	a[303] = 1000000 + 6;
	a[398] = 1000000 + 7;
	a[420] = 1000000 + 8;
	a[982] = 1000000 + 9;
	a[740] = 1000000 + 10;

	PrintTopK(a, n, 10);
}