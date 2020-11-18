void printKDistant(node *root , int k)  
{  
    if(root == NULL)  
        return;  
    if( k == 0 )  
    {  
        cout << root->data << " ";  
        return ;  
    }  
    else
    {  
        printKDistant( root->left, k - 1 ) ;  
        printKDistant( root->right, k - 1 ) ;  
    }  
}  