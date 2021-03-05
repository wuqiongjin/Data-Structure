#include "List.h"

void ListInit(ListNode* pHead)
{
	pHead->next = pHead;
	pHead->prev = pHead;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newNode = BuyListNode(x);

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = pHead;
	pHead->prev = newNode;
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead != pHead->next);

	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;

	tailPrev->next = pHead;
	pHead->prev = tailPrev;
	free(tail);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newNode = BuyListNode(x);
	ListNode* first = pHead->next;

	first->prev = newNode;
	newNode->next = first;
	newNode->prev = pHead;
	pHead->next = newNode;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead != pHead->next);

	ListNode* first = pHead->next;
	ListNode* second = first->next;

	pHead->next = second;
	second->prev = pHead;
	free(first);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);

	ListNode* posPrev = pos->prev;
	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;

}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void ListClear(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;

	while (cur != pHead)
	{
		ListNode* del = cur;
		cur = cur->next;
		free(del);
	}
}

void ListDestory(ListNode** ppHead)
{
	assert(*ppHead);
	ListClear(*ppHead);

	*ppHead = NULL;
	free(*ppHead);
}