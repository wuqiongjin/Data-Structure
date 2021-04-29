#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinaryTree.h"

//typedef struct TreeNode
//{
//	char val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//}TreeNode;


//前置声明
//什么时候用前置声明？？？？ 自己要分析这个文件要在哪里展开
//这个queue.h会在BinaryTree.h前面展开，但是由于还没有出现struct TreeNode结构体的定义，所以下面的这段代码是错误的
//因此，我们需要使用前置声明，让编译器知道有这个结构体，这样就没问题了
//1.第一种
//typedef struct TreeNode TreeNode;
//typedef TreeNode* QDataType;
//2.第二种
struct TreeNode;
typedef struct TreeNode* QDataType;



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


	//我可真给你面子xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	//这逼错误我找了1年，真是xxxxxxxxxxxxxxx了
	//我这辈子不会忘了，动态申请结点时，要注意初始化结点的内容！！！！！！！！！！！！！！！！
	//所以建议用new，这样就不会出现忘记初始化的问题了。。。。。。。。。。
	newNode->next = NULL;
	
	
	
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

//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	
//	printf("%d ", QueueFront(&q)->data);
//	printf("%d ", QueueBack(&q)->data);
//
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ", q.qhead->data);
//		QueuePop(&q);
//	}
//
//	
//	QueueDestory(&q);
//}