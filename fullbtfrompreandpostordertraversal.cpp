// A recursive function to construct Full from pre[] and post[].  
// preIndex is used to keep track of index in pre[].  
// l is low index and h is high index for the current subarray in post[]  
node* constructTreeUtil (int pre[], int post[], int* preIndex,  
                                int l, int h, int size)  
{  
    // Base case  
    if (*preIndex >= size || l > h)  
        return NULL;  
  
    // The first node in preorder traversal is root. So take the node at  
    // preIndex from preorder and make it root, and increment preIndex  
    node* root = newNode ( pre[*preIndex] );  
    ++*preIndex;  
  
    // If the current subarry has only one element, no need to recur  
    if (l == h)  
        return root;  
  
    // Search the next element of pre[] in post[]  
    int i;  
    for (i = l; i <= h; ++i)  
        if (pre[*preIndex] == post[i])  
            break;  
  
    // Use the index of element found in postorder to divide  
        // postorder array in two parts. Left subtree and right subtree  
    if (i <= h)  
    {  
        root->left = constructTreeUtil (pre, post, preIndex, 
                                                l, i, size);  
        root->right = constructTreeUtil (pre, post, preIndex,  
                                                 i + 1, h, size);  
    }  
  
    return root;  
}  
  
// The main function to construct Full Binary Tree from given preorder and  
// postorder traversals. This function mainly uses constructTreeUtil()  
node *constructTree (int pre[], int post[], int size)  
{  
    int preIndex = 0;  
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);  
}  