int cntnode(struct Node *root)
{
    if(root==NULL)
    return 0;
    else
    return 1+cntnode(root->left)+cntnode(root->right);
}
float findMedian(struct Node *root,int n)
{
    if(root==NULL)
    return 0;
    int cnt = cntnode(root);
    int count=0;
    struct Node* cur = root,*pre,*prev;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            count++;
            if(cnt%2==1&&count==(cnt+1)/2)
                return cur->data;
                if(cnt%2==0&&count==(cnt/2+1))
                return ((float)(cur->data+prev->data))/2;
            prev = cur;
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while(pre->right!=NULL&&pre->right!=cur)
            pre = pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur = cur->left;
                
            }
            else
            {
                pre->right = NULL;
                prev = pre;
                count++;
                if(cnt%2==1&&count==(cnt+1)/2)
                return cur->data;
                if(cnt%2==0&&count==(cnt/2+1))
                return ((float)(cur->data+prev->data))/2;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    
      //Code here
}