// A simple inorder traversal based 
// program to convert a Binary Tree to DLL 
#include <bits/stdc++.h> 
using namespace std; 

// A tree node 
class node 
{ 
	public: 
	int data; 
	node *left, *right; 
}; 

// A utility function to create 
// a new tree node 
node *newNode(int data) 
{ 
	node *Node = new node(); 
	Node->data = data; 
	Node->left = Node->right = NULL; 
	return(Node); 
} 

// Standard Inorder traversal of tree 
void inorder(node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout << "\t" << root->data; 
		inorder(root->right); 
	} 
} 

// Changes left pointers to work as 
// previous pointers in converted DLL 
// The function simply does inorder 
// traversal of Binary Tree and updates 
// left pointer using previously visited node 
void fixPrevPtr(node *root) 
{ 
	static node *pre = NULL; 

	if (root != NULL) 
	{ 
		fixPrevPtr(root->left); 
		root->left = pre; 
		pre = root; 
		fixPrevPtr(root->right); 
	} 
} 

// Changes right pointers to work 
// as next pointers in converted DLL 
node *fixNextPtr(node *root) 
{ 
	node *prev = NULL; 

	// Find the right most node 
	// in BT or last node in DLL 
	while (root && root->right != NULL) 
		root = root->right; 

	// Start from the rightmost node, 
	// traverse back using left pointers. 
	// While traversing, change right pointer of nodes. 
	while (root && root->left != NULL) 
	{ 
		prev = root; 
		root = root->left; 
		root->right = prev; 
	} 

	// The leftmost node is head 
	// of linked list, return it 
	return (root); 
} 

// The main function that converts 
// BST to DLL and returns head of DLL 
node *BTToDLL(node *root) 
{ 
	// Set the previous pointer 
	fixPrevPtr(root); 

	// Set the next pointer and return head of DLL 
	return fixNextPtr(root); 
} 

// Traverses the DLL from left tor right 
void printList(node *root) 
{ 
	while (root != NULL) 
	{ 
		cout<<"\t"<<root->data; 
		root = root->right; 
	} 
} 

// Driver code 
int main(void) 
{ 
	// Let us create the tree 
	// shown in above diagram 
	node *root = newNode(10); 
	root->left = newNode(12); 
	root->right = newNode(15); 
	root->left->left = newNode(25); 
	root->left->right = newNode(30); 
	root->right->left = newNode(36); 

	cout<<"\n\t\tInorder Tree Traversal\n\n"; 
	inorder(root); 

	node *head = BTToDLL(root); 

	cout << "\n\n\t\tDLL Traversal\n\n"; 
	printList(head); 
	return 0; 
} 

// This code is contributed by rathbhupendra 


//2nd method
// A C++ program for in-place conversion of Binary Tree to DLL 
#include <iostream> 
using namespace std; 

/* A binary tree node has data, and left and right pointers */
struct node 
{ 
	int data; 
	node* left; 
	node* right; 
}; 

// A simple recursive function to convert a given Binary tree to Doubly 
// Linked List 
// root --> Root of Binary Tree 
// head --> Pointer to head node of created doubly linked list 
void BinaryTree2DoubleLinkedList(node *root, node **head) 
{ 
	// Base case 
	if (root == NULL) return; 

	// Initialize previously visited node as NULL. This is 
	// static so that the same value is accessible in all recursive 
	// calls 
	static node* prev = NULL; 

	// Recursively convert left subtree 
	BinaryTree2DoubleLinkedList(root->left, head); 

	// Now convert this node 
	if (prev == NULL) 
		*head = root; 
	else
	{ 
		root->left = prev; 
		prev->right = root; 
	} 
	prev = root; 

	// Finally convert right subtree 
	BinaryTree2DoubleLinkedList(root->right, head); 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
node* newNode(int data) 
{ 
	node* new_node = new node; 
	new_node->data = data; 
	new_node->left = new_node->right = NULL; 
	return (new_node); 
} 

/* Function to print nodes in a given doubly linked list */
void printList(node *node) 
{ 
	while (node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->right; 
	} 
} 

/* Driver program to test above functions*/
int main() 
{ 
	// Let us create the tree shown in above diagram 
	node *root	 = newNode(10); 
	root->left	 = newNode(12); 
	root->right	 = newNode(15); 
	root->left->left = newNode(25); 
	root->left->right = newNode(30); 
	root->right->left = newNode(36); 

	// Convert to DLL 
	node *head = NULL; 
	BinaryTree2DoubleLinkedList(root, &head); 

	// Print the converted list 
	printList(head); 

	return 0; 
} 
