#pragma once
#include "SList.h"

//SListNode* BuySListNode(SListNode** phead)
//{
//	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
//	if (newNode == NULL)
//	{
//		exit(-1);
//	}
//	return newNode;
//}
//
//void SListPushBack(SListNode** phead, SLDataType x)
//{
//	//1.找到尾结点/如果链表为空跳过这个步骤
//	SListNode* tail = *phead;
//	if (*phead != NULL)
//	{
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//	}
//	else
//	{
//		tail = (SListNode*)malloc(sizeof(SListNode));
//		tail->data = x;
//		return;
//	}
//	//2.进行插入
//	SListNode* newNode = BuySListNode(phead);
//	tail->next = newNode;
//	tail->data = x;
//}

//SListNode* BuySListNode(SLDataType x)
//{
//	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
//	if (newNode == NULL)
//	{
//		perror("BUYERROR:");
//	}
//	newNode->next = NULL;
//	newNode->data = x;
//	return newNode;
//}
//
//void SListPushBack(SListNode** phead, SLDataType x)
//{
//	//判断phead是否为NULL
//	if (*phead == NULL)
//	{
//		*phead = BuySListNode(x);
//		return;
//	}
//	//phead不是NULL时的插入操作
//	//1.找到尾结点
//	SListNode* tail = *phead;
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	//2.插入新结点
//	tail->next = BuySListNode(x);
//}
//
//void SListPrint(SListNode* phead)
//{
//	while (phead != NULL)
//	{
//		printf("%d->", phead->data);
//		phead = phead->next;
//	}
//}
//
//void SListPopBack(SListNode** phead)
//{
//	if (*phead != NULL)
//	{
//		//处理多个结点的尾删(>1)
//		if ((*phead)->next != NULL)
//		{
//			SListNode* tail = *phead;
//			SListNode* prev = *phead;
//			while (tail->next != NULL)
//			{
//				prev = tail;
//				tail = tail->next;
//			}
//			free(tail);
//			prev->next = NULL;
//		}
//		else//处理只有1个结点的尾删
//		{
//			free(*phead);
//			*phead = NULL;
//		}
//	}
//}
//
//void SListPushFront(SListNode** phead, SLDataType x)
//{
//	SListNode* head = *phead;
//	*phead = BuySListNode(x);
//	(*phead)->next = head;
//}
//
//void SListPopFront(SListNode** phead)
//{
//	//链表不为空
//	if (*phead)
//	{
//		SListNode* prev = *phead;
//		*phead = (*phead)->next;
//		free(prev);
//	}
//	else//链表为空
//	{
//		return;
//	}
//}
//
//void SListInsertAfter(SListNode* pos, SLDataType x)
//{
//	assert(pos);
//	SListNode* insert = BuySListNode(x);
//	insert->next = pos->next;
//	pos->next = insert;
//}
//
//void SListEraseAfter(SListNode* pos)
//{
//	assert(pos);
//	if (pos->next)//确保pos后面不是NULL再删除
//	{
//		SListNode* next = pos->next;
//		pos->next = next->next;
//		free(next);
//	}
//}