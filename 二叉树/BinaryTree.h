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
//二叉树的层序遍历
void TreeLevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);

	//先入根节点
	if(root != NULL)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{ 
		//将根节点pop出来，再带入左子树的根节点和右子树的根节点
		TreeNode* ret = QueueFront(&q)->data;
		QueuePop(&q);

		printf("%c ", ret->val);

		//不为空，才入
		if(ret->left)
			QueuePush(&q, ret->left);

		if(ret->right)
			QueuePush(&q, ret->right);
		
	}

	printf("\n");
	QueueDestory(&q);
}
//
////判断完全二叉树
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
//			return 0;//出去的时候遇到非空，那么不是完全二叉树
//		QueuePop(&q);
//	}
//	return 1;
//}