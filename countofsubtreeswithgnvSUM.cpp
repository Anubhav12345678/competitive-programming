// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int sumofsubtree(Node *root)
{
    if(root==NULL)
    return 0;
    return root->data+sumofsubtree(root->left)+sumofsubtree(root->right);
}
int countSubtreesWithSumX(Node* root, int x)
{
	if (!root)return 0;
	if(sumofsubtree(root)==x)
	return 1+countSubtreesWithSumX(root->left,x)+countSubtreesWithSumX(root->right,x);
	else
	return countSubtreesWithSumX(root->left,x)+countSubtreesWithSumX(root->right,x);
	
	// Code here
}
