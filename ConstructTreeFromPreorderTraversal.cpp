struct Node* newnode(int k)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data=k;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
struct Node* util(int pre[],char preLN[],int n,int *indptr)
{
    int ind = *indptr;
    if(ind==n)
    return NULL;
    struct Node* tmp = newnode(pre[ind]);
    (*indptr)++;
    if(preLN[ind]=='N')
    {
        tmp->left = util(pre,preLN,n,indptr);
        tmp->right = util(pre,preLN,n,indptr);
    }
    return tmp;
    
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int ind=0;
    return util(pre,preLN,n,&ind);
    // Code here
}