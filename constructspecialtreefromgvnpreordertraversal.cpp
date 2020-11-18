/* 
Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children. 
One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the 
corresponding node in Binary Tree is a leaf node and
 value ‘N’ indicates that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.

Example:

Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5





A recursive function to create a Binary Tree from given pre[] 
   preLN[] arrays. The function returns root of tree. index_ptr is used 
   to update index values in recursive calls. index must be initially 
   passed as 0 */
struct node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n) 
{ 
    int index = *index_ptr; // store the current value of index in pre[] 
  
    // Base Case: All nodes are constructed 
    if (index == n) 
        return NULL; 
  
    // Allocate memory for this node and increment index for 
    // subsequent recursive calls 
    struct node *temp = newNode ( pre[index] ); 
    (*index_ptr)++; 
  
    // If this is an internal node, construct left and right subtrees and link the subtrees 
    if (preLN[index] == 'N') 
    { 
      temp->left  = constructTreeUtil(pre, preLN, index_ptr, n); 
      temp->right = constructTreeUtil(pre, preLN, index_ptr, n); 
    } 
  
    return temp; 
} 
  
// A wrapper over constructTreeUtil() 
struct node *constructTree(int pre[], char preLN[], int n) 
{ 
    // Initialize index as 0. Value of index is used in recursion to maintain 
    // the current index in pre[] and preLN[] arrays. 
    int index = 0; 
  
    return constructTreeUtil (pre, preLN, &index, n); 
} 