int TreeLeafSize(BTNode* root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}