#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "queue.h"


typedef struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


TreeNode* BuildpreorderTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = str[*pi];
		++(*pi);
		root->left = BuildpreorderTree(str, pi);
		++(*pi);
		root->right = BuildpreorderTree(str, pi);
		return root;
	}
}

void printinorder(struct TreeNode* root)
{
	if (root == NULL)
		return;
	printinorder(root->left);
	printf("%c ", root->val);
	printinorder(root->right);
}
//
//TreeNode* TreeFind(TreeNode* root, char x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->val == x)
//		return root;
//	TreeNode* ret = TreeFind(root->left, x);
//	if (ret)
//	{
//		return ret;
//	}
//	ret = TreeFind(root->right, x);
//	if (ret)
//	{
//		return ret;
//	}
//	return NULL;
//}
//
//
//�������Ĳ������
void TreeLevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);

	//������ڵ�
	if(root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{ 
		//�����ڵ�pop�������ٴ����������ĸ��ڵ���������ĸ��ڵ�
		TreeNode* ret = QueueFront(&q)->data;
		QueuePop(&q);

		printf("%c ", ret->val);

		//��Ϊ�գ�����
		if(ret->left)
			QueuePush(&q, ret->left);

		if(ret->right)
			QueuePush(&q, ret->right);
		
	}

	printf("\n");
	QueueDestory(&q);
}
//
////�ж���ȫ������
//int TreeComplete(TreeNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//
//	if (root != NULL)
//		QueuePush(&q, root);
//	else
//		return 1;
//
//	while (!QueueEmpty(&q))
//	{
//		TreeNode* ret = QueueFront(&q)->data;
//		QueuePop(&q);
//
//		if (ret == NULL)
//		{
//			break;
//		}
//		
//		QueuePush(&q, ret->left);
//		QueuePush(&q, ret->right);
//	}
//
//	while (!QueueEmpty(&q))
//	{
//		if (QueueFront(&q) != NULL)
//			return 0;//��ȥ��ʱ�������ǿգ���ô������ȫ������
//		QueuePop(&q);
//	}
//	return 1;
//}