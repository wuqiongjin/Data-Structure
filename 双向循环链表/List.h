#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

void ListInit(ListNode* pHead);

ListNode* BuyListNode(LTDataType x);
//β����
void ListPushBack(ListNode* pHead, LTDataType x);
//βɾ
void ListPopBack(ListNode* pHead);

void ListPrint(ListNode* pHead);

void ListPushFront(ListNode* pHead, LTDataType x);

void ListPopFront(ListNode* pHead);

ListNode* ListFind(ListNode* pHead, LTDataType x);
//��posλ�� ǰ�� ��������x
void ListInsert(ListNode* pos, LTDataType x);
//ɾ��posλ�õ�����
void ListErase(ListNode* pos);

//���˫������
void ListClear(ListNode* pHead);
//����˫������
void ListDestory(ListNode** ppHead);