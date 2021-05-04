BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == nullptr)
		return nullptr;
	if (root->val == x)
		return root;
	//找左边的
	BTNode* Left = TreeFind(root->left, x);
	//不为空就代表找到了，找到就返回，就不用去右边找了
	if (Left)
		return Left;
	//左边没找到，去右边找
	BTNode* Right = TreeFind(root->right, x);
	if (Right)
		return Right;
	//都没找到，返回nullptr
	return nullptr;
}