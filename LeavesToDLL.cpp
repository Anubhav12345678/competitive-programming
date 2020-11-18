Node *convertToDLL(Node *root,Node **head_ref)
{
    if(root==NULL)
    return NULL;
    if(root->right==NULL&&root->left==NULL)
    {
        root->right=*head_ref;
        if(*head_ref!=NULL)
        (*head_ref)->left=root;
        *head_ref=root;
        return NULL;
    }
    root->right = convertToDLL(root->right,head_ref);
    root->left = convertToDLL(root->left,head_ref);
    return root;
    // root->right = convertToDLL(root->right,head_ref);
//add code here.
}