
/*



Question: Given a binary tree, find out if the tree can be folded or not.

A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree 
is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.

(a)
       10
     /    \
    7      15
     \    /
      9  11

(b)
        10
       /  \
      7    15
     /      \
    9       11

(c)
        10
       /  \
      7   15
     /    /
    5   11

(d)

         10
       /   \
      7     15
    /  \    /
   9   10  12

*/

bool isFoldable(node* root) 
{ 
    bool res; 
  
    /* base case */
    if (root == NULL) 
        return true; 
  
    /* convert left subtree to its mirror */
    mirror(root->left); 
  
    /* Compare the structures of the  
    right subtree and mirrored  
    left subtree */
    res = isStructSame(root->left, root->right); 
  
    /* Get the originial tree back */
    mirror(root->left); 
  
    return res; 
} 
  
bool isStructSame(node* a, node* b) 
{ 
    if (a == NULL && b == NULL) { 
        return true; 
    } 
    if (a != NULL && b != NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right)) { 
        return true; 
    } 
  
    return false; 
} 
  
/* UTILITY FUNCTIONS */
/* Change a tree so that the roles of the left and  
    right pointers are swapped at every node.  
    See https:// www.geeksforgeeks.org/?p=662 for details */
void mirror(node* Node) 
{ 
    if (Node == NULL) 
        return; 
    else { 
        node* temp; 
  
        /* do the subtrees */
        mirror(Node->left); 
        mirror(Node->right); 
  
        /* swap the pointers in this node */
        temp = Node->left; 
        Node->left = Node->right; 
        Node->right = temp; 
    } 
} 