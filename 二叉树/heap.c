#include "heap.h"

//���µ����㷨
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		//���Ӻ��Һ��ӽ��бȽϣ�ѡ����С�ġ����û���Һ��ӣ������иñȽϡ�
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		//�жϺ��ӽڵ�͸��ڵ㡾����С�ѡ�
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
	//�ѵĿռ俪�ٺͳ�ʼ��
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*sz);
	hp->_size = sz;
	hp->_capacity = sz;
	//���ݵĿ���
	memcpy(hp->_a, a, sizeof(HpDataType)*sz);

	//�ѵĴ���
	int i = 0;
	for (i = (sz - 1 - 1) / 2;i >= 0;--i)
	{
		AdjustDown(hp->_a, sz, i);
	}
}

void HeapPush(Heap* hp, HpDataType x)
{
	//���ݲ���
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = 2 * hp->_capacity;
		hp->_a = realloc(hp->_a, sizeof(HpDataType)*newCapacity);
		hp->_capacity = newCapacity;
	}

	//����в���Ԫ��
	hp->_a[hp->_size] = x;
	hp->_size++;

	//���ϵ����㷨
	AdjustUp(hp->_a, hp->_size - 1);
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//���ϵ���
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