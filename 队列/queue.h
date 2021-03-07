#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//队列结点的结构体
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//队列结构体
typedef struct Queue
{
	QueueNode* qhead;
	QueueNode* qtail;
}Queue;


//初始化队列
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
	//队列没有结点的时候
	if (q->qhead == NULL)
	{
		q->qtail = q->qhead = newNode;
	}
	else//队列存在结点时候
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
	//当有多个结点时的，出队列
	if (q->qhead->next)
	{
		QueueNode* next = q->qhead->next;
		free(q->qhead);
		q->qhead = next;
	}
	else//只有1个结点时，出队列
	{
		QueueNode* next = q->qhead->next;
		free(q->qhead);
		q->qhead = q->qtail = NULL;
	}
}

//获取队头结点
QueueNode* QueueFront(Queue* q)
{
	assert(q);
	return q->qhead;
}

//获取队尾结点
QueueNode* QueueBack(Queue* q)
{
	assert(q);
	return q->qtail;
}

//判断队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->qhead ? 0 : 1;
}

//获取队列中有效元素的个数
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


//队列的销毁
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