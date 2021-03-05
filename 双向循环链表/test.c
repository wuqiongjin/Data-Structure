#include "List.h"

ListTest1()
{
	ListNode* pHead = BuyListNode(0);
	ListInit(pHead);

	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);

	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);

	ListPushFront(pHead, -1);
	ListPushFront(pHead, -2);
	ListPushFront(pHead, -3);
	ListPrint(pHead);

	ListPopFront(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);

	ListClear(pHead);
	ListDestory(&pHead);
}

void ListTest2()
{
	ListNode* pHead = BuyListNode(0);
	ListInit(pHead);

	ListPushBack(pHead, 100);
	ListPushBack(pHead, 200);
	ListPushBack(pHead, 300);
	ListPrint(pHead);

 	ListNode* pos = ListFind(pHead, 200);
	ListInsert(pos, 233);
	ListPrint(pHead);
	
	ListErase(pos);
	ListPrint(pHead);

	ListClear(pHead);
	ListDestory(&pHead);
}

int main()
{
	ListTest2();
}