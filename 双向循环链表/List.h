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
//尾插结点
void ListPushBack(ListNode* pHead, LTDataType x);
//尾删
void ListPopBack(ListNode* pHead);

void ListPrint(ListNode* pHead);

void ListPushFront(ListNode* pHead, LTDataType x);

void ListPopFront(ListNode* pHead);

ListNode* ListFind(ListNode* pHead, LTDataType x);
//在pos位置 前面 插入数据x
void ListInsert(ListNode* pos, LTDataType x);
//删除pos位置的数据
void ListErase(ListNode* pos);

//清空双向链表
void ListClear(ListNode* pHead);
//销毁双向链表
void ListDestory(ListNode** ppHead);