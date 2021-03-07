#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//���н��Ľṹ��
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//���нṹ��
typedef struct Queue
{
	QueueNode* qhead;
	QueueNode* qtail;
}Queue;


//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->qhead = q->qtail = NULL;
}


void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	QueueNode* prev = q->qtail;
	//����û�н���ʱ��
	if (q->qhead == NULL)
	{
		q->qtail = q->qhead = newNode;
	}
	else//���д��ڽ��ʱ��
	{
		q->qtail = newNode;
		prev->next = newNode;
	}
	newNode->data = x;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->qhead);
	//���ж�����ʱ�ģ�������
	if (q->qhead->next)
	{
		QueueNode* next = q->qhead->next;
		free(q->qhead);
		q->qhead = next;
	}
	else//ֻ��1�����ʱ��������
	{
		QueueNode* next = q->qhead->next;
		free(q->qhead);
		q->qhead = q->qtail = NULL;
	}
}

//��ȡ��ͷ���
QueueNode* QueueFront(Queue* q)
{
	assert(q);
	return q->qhead;
}

//��ȡ��β���
QueueNode* QueueBack(Queue* q)
{
	assert(q);
	return q->qtail;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->qhead ? 0 : 1;
}

//��ȡ��������ЧԪ�صĸ���
int QueueSize(Queue* q)
{
	assert(q);
	QueueNode* cur = q->qhead;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


//���е�����
void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->qhead;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	
	printf("%d ", QueueFront(&q)->data);
	printf("%d ", QueueBack(&q)->data);

	while (!QueueEmpty(&q))
	{
		printf("%d ", q.qhead->data);
		QueuePop(&q);
	}

	
	QueueDestory(&q);
}