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
//	//1.�ҵ�β���/�������Ϊ�������������
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
//	//2.���в���
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
//	//�ж�phead�Ƿ�ΪNULL
//	if (*phead == NULL)
//	{
//		*phead = BuySListNode(x);
//		return;
//	}
//	//phead����NULLʱ�Ĳ������
//	//1.�ҵ�β���
//	SListNode* tail = *phead;
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	//2.�����½��
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
//		//����������βɾ(>1)
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
//		else//����ֻ��1������βɾ
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
//	//����Ϊ��
//	if (*phead)
//	{
//		SListNode* prev = *phead;
//		*phead = (*phead)->next;
//		free(prev);
//	}
//	else//����Ϊ��
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
//	if (pos->next)//ȷ��pos���治��NULL��ɾ��
//	{
//		SListNode* next = pos->next;
//		pos->next = next->next;
//		free(next);
//	}
//}