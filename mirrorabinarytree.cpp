void mirror(Node* node) 
{
    if(node==NULL)
    return;
    if(node->left==NULL&&node->right==NULL)return;
    if(node->left==NULL||node->right==NULL)return;
    Node* tmp;
    tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    mirror(node->right);
    mirror(node->left);
    return;
    // mirror(node->right);
    // mirror(node->left);
     // Your Code Here
}