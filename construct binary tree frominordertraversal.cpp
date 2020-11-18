

/*


Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children, 
construct the Binary Tree and return root.
Examples:

Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28 

Input: inorder[] = {1, 5, 10, 40, 30, 
                    15, 28, 20}
Output: root of following tree
          40
        /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20


*/

node* buildTree (int inorder[], int start, int end)  
{  
    if (start > end)  
        return NULL;  
  
    /* Find index of the maximum element from Binary Tree */
    int i = max (inorder, start, end);  
  
    /* Pick the maximum value and make it root */
    node *root = newNode(inorder[i]);  
  
    /* If this is the only element in inorder[start..end],  
    then return it */
    if (start == end)  
        return root;  
  
    /* Using index in Inorder traversal, construct left and  
    right subtress */
    root->left = buildTree (inorder, start, i - 1);  
    root->right = buildTree (inorder, i + 1, end);  
  
    return root;  
}  
  
/* UTILITY FUNCTIONS */
/* Function to find index of the maximum value in arr[start...end] */
int max (int arr[], int strt, int end)  
{  
    int i, max = arr[strt], maxind = strt;  
    for(i = strt + 1; i <= end; i++)  
    {  
        if(arr[i] > max)  
        {  
            max = arr[i];  
            maxind = i;  
        }  
    }  
    return maxind;  
}  
  