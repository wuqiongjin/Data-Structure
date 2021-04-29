#pragma once
#include "BinaryTree.h"
#include "queue.h"


int main()
{
	//char str[100] = { "ABC##DE#G##F###" };
	char str[100] = { "ABD##E##C#F##" };
	int i = 0;
	struct TreeNode* root = BuildpreorderTree(str, &i);
	//abc##de#g##f###
	//TreeNode* ret = TreeFind(root, 'D');

	TreeLevelOrder(root);
	//printinorder(root);
	//printf("%c\n", ret->val);

	return 0;
}