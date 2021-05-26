#include "Heap.h"


int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 9 };
	int n = sizeof(a) / sizeof(a[0]);
	Heap<int> hp;
	hp.HeapCreate(a, n);
	hp.Print();
	
	//hp.Push(3);
	//hp.Print();
	//hp.Push(4);
	//hp.Print();

	//hp.Pop();
	
	cout << hp.Top() << endl;
	hp.Print();
	
	HeapSort(hp);
	hp.Print();

	return 0;
}