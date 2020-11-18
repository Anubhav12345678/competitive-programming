    /* 

Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a 
node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree 
can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3








returns 1 if SumTree property holds for the given 
    tree 



    */
int isSumTree(struct node* node) 
{ 
    int ls; // for sum of nodes in left subtree 
    int rs; // for sum of nodes in right subtree 
  
    /* If node is NULL or it's a leaf node then 
       return true */
    if(node == NULL || isLeaf(node)) 
        return 1; 
  
    if( isSumTree(node->left) && isSumTree(node->right)) 
    { 
        // Get the sum of nodes in left subtree 
        if(node->left == NULL) 
            ls = 0; 
        else if(isLeaf(node->left)) 
            ls = node->left->data; 
        else
            ls = 2*(node->left->data); 
  
        // Get the sum of nodes in right subtree 
        if(node->right == NULL) 
            rs = 0; 
        else if(isLeaf(node->right)) 
            rs = node->right->data; 
        else
            rs = 2*(node->right->data); 
  
        /* If root's data is equal to sum of nodes in left 
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs); 
    } 
  
    return 0; 
} 