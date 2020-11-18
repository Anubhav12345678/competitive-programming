// C program to find the mirror Node in Binary tree 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree Node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

// create new Node and initialize it 
struct Node* newNode(int key) 
{ 
	struct Node* n = (struct Node*) 
					malloc(sizeof(struct Node*)); 
	if (n != NULL) 
	{ 
		n->key = key; 
		n->left = NULL; 
		n->right = NULL; 
		return n; 
	} 
	else
	{ 
		printf("Memory allocation failed!"); 
		exit(1); 
	} 
} 

// recursive function to find mirror of Node 
int findMirrorRec(int target, struct Node* left, 
							struct Node* right) 
{ 
	/* if any of the Node is none then Node itself 
	and decendent have no mirror, so return 
	none, no need to further explore! */
	if (left==NULL || right==NULL) 
		return 0; 

	/* if left Node is target Node, then return 
	right's key (that is mirror) and vice 
	versa */
	if (left->key == target) 
		return right->key; 

	if (right->key == target) 
		return left->key; 

	// first recur external Nodes 
	int mirror_val = findMirrorRec(target, 
									left->left, 
									right->right); 
	if (mirror_val) 
		return mirror_val; 

	// if no mirror found, recur internal Nodes 
	findMirrorRec(target, left->right, right->left); 
} 

// interface for mirror search 
int findMirror(struct Node* root, int target) 
{ 
	if (root == NULL) 
		return 0; 
	if (root->key == target) 
		return target; 
	return findMirrorRec(target, root->left, root->right); 
} 

// Driver 
int main() 
{ 
	struct Node* root		 = newNode(1); 
	root-> left				 = newNode(2); 
	root->left->left		 = newNode(4); 
	root->left->left->right	 = newNode(7); 
	root->right				 = newNode(3); 
	root->right->left		 = newNode(5); 
	root->right->right		 = newNode(6); 
	root->right->left->left	 = newNode(8); 
	root->right->left->right = newNode(9); 

	// target Node whose mirror have to be searched 
	int target = root->left->left->key; 

	int mirror = findMirror(root, target); 

	if (mirror) 
		printf("Mirror of Node %d is Node %d\n", 
									target, mirror); 
	else
		printf("Mirror of Node %d is NULL!\n", target); 
} 
