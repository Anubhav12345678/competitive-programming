void printPaths(node* node)  
{  
    int path[1000];  
    printPathsRecur(node, path, 0);  
}  
  
/* Recursive helper function -- given a node,  
and an array containing the path from the root 
node up to but not including this node,  
print out all the root-leaf paths.*/
void printPathsRecur(node* node, int path[], int pathLen)  
{  
    if (node == NULL)  
        return;  
      
    /* append this node to the path array */
    path[pathLen] = node->data;  
    pathLen++;  
      
    /* it's a leaf, so print the path that led to here */
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
        /* otherwise try both subtrees */
        printPathsRecur(node->left, path, pathLen);  
        printPathsRecur(node->right, path, pathLen);  
    }  
}  
  