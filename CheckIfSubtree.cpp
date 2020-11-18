bool areid(Node *a,Node *b)
{
    if(a==NULL&&b==NULL)
    return true;
    if(a==NULL||b==NULL)
    return false;
    return (a->data==b->data&&areid(a->left,b->left)&&areid(a->right,b->right));
}
bool isSubtree(Node* T1, Node* T2) {
    if(T2==NULL)
    return true;
    if(T1==NULL)
    return false;
    if(areid(T1,T2))
    return true;
    return isSubtree(T1->left,T2)||isSubtree(T1->right,T2);
    // Your code here
    // return 1 if T2 is subtree of T1 else 0
}