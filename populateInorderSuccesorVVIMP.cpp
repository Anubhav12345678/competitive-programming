/* Set next of p and all descendents of p  
by traversing them in reverse Inorder */
void populateNext(node* p)  
{  
    // The first visited node will be the  
    // rightmost node next of the rightmost  
    // node will be NULL  
    static node *next = NULL;  
  
    if (p)  
    {  
        // First set the next pointer  
        // in right subtree  
        populateNext(p->right);  
  
        // Set the next as previously visited 
        // node in reverse Inorder  
        p->next = next;  
  
        // Change the prev for subsequent node  
        next = p;  
  
        // Finally, set the next pointer in 
        // left subtree  
        populateNext(p->left);  
    }  
}  