struct node * inOrderSuccessor(struct node *root, struct node *n) 
{ 
  // step 1 of the above algorithm  
  if( n->right != NULL ) 
    return minValue(n->right); 
  
  // step 2 of the above algorithm 
  struct node *p = n->parent; 
  while(p != NULL && n == p->right) 
  { 
     n = p; 
     p = p->parent; 
  } 
  return p; 
} 
  
/* Given a non-empty binary search tree, return the minimum data   
    value found in that tree. Note that the entire tree does not need 
    to be searched. */
struct node * minValue(struct node* node) { 
  struct node* current = node; 
   
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) { 
    current = current->left; 
  } 
  return current; 
} 