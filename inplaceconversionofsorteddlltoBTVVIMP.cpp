Node* sortedListToBST(Node *head)  
{  
    /*Count the number of nodes in Linked List */
    int n = countNodes(head);  
  
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);  
}  
  
/* The main function that constructs  
balanced BST and returns root of it.  
head_ref --> Pointer to pointer to 
head node of Doubly linked list  
n --> No. of nodes in the Doubly Linked List */
Node* sortedListToBSTRecur(Node **head_ref, int n)  
{  
    /* Base Case */
    if (n <= 0)  
        return NULL;  
  
    /* Recursively construct the left subtree */
    Node *left = sortedListToBSTRecur(head_ref, n/2);  
  
    /* head_ref now refers to middle node, 
    make middle node as root of BST*/
    Node *root = *head_ref;  
  
    // Set pointer to left subtree  
    root->prev = left;  
  
    /* Change head pointer of Linked List 
    for parent recursive calls */
    *head_ref = (*head_ref)->next;  
  
    /* Recursively construct the right  
    subtree and link it with root  
    The number of nodes in right subtree 
    is total nodes - nodes in  
    left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);  
  
    return root;  
}  
  