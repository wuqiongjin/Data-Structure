#include "List.h"


void testList()
{
	//ʹ����ģ��ȥʵ���� �����ʱ��Ҫ������������ ��<int>
	ListNode<int>* pHead = new ListNode<int>;
	
	//new(pHead)ListNode<int>(pHead);

	pHead->PushBack(1);
	pHead->PushBack(2);
	pHead->PushBack(3);

	pHead->PushFront(-1);
	pHead->PushFront(-2);
	pHead->PushFront(-3);

	pHead->PopBack();
	pHead->PopFront();

	ListNode<int>* res = pHead->Find(1);
	pHead->Insert(res, 666);
	pHead->Print();

	pHead->Erase(res);

	pHead->Print();
}


int main()
{
	testList();
	return 0;
}