#include "heap.h"

void TestHp(HpDataType* a, int sz)
{
	Heap hp;
	HeapCreate(&hp, a, sz);
	HeapPrint(&hp);


	HeapPush(&hp, 25);
	HeapPrint(&hp);

	HeapPush(&hp, 13);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	//HeapSort(&hp);
	//HeapPrint(&hp);

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(a) / sizeof(a[0]);
	TestHp(a, sz);
}