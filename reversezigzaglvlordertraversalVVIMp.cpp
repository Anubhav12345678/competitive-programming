// C++ program to print reverse 
// zigzag order of binary tree 
#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
struct node { 
	struct node* left; 
	struct node* right; 
	int data; 
}; 

// Function to create a new 
// Binary node 
struct node* newNode(int data) 
{ 
	struct node* temp = new node; 

	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 

	return temp; 
} 

// Recursive Function to find height 
// of binary tree 
int HeightOfTree(struct node* root) 
{ 
	if (root == NULL) 
		return 0; 

	// Compute the height of each subtree 
	int lheight = HeightOfTree(root->left); 
	int rheight = HeightOfTree(root->right); 

	// Return the maximum of two 
	return max(lheight + 1, rheight + 1); 
} 

// Function to Print nodes from right to left 
void Print_Level_Right_To_Left(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 

	if (level == 1) 
		cout << root->data << " "; 

	else if (level > 1) { 
		Print_Level_Right_To_Left(root->right, level - 1); 
		Print_Level_Right_To_Left(root->left, level - 1); 
	} 
} 

// Function to Print nodes from left to right 
void Print_Level_Left_To_Right(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 

	if (level == 1) 
		cout << root->data << " "; 

	else if (level > 1) { 
		Print_Level_Left_To_Right(root->left, level - 1); 
		Print_Level_Left_To_Right(root->right, level - 1); 
	} 
} 

// Function to print Reverse zigzag of 
// a Binary tree 
void PrintReverseZigZag(struct node* root) 
{ 
	// Flag is used to mark the change 
	// in level 
	int flag = 1; 

	// Height of tree 
	int height = HeightOfTree(root); 

	for (int i = height; i >= 1; i--) { 

		// If flag value is one print nodes 
		// from right to left 
		if (flag == 1) { 
			Print_Level_Right_To_Left(root, i); 

			// Mark flag as zero so that next time 
			// tree is traversed from left to right 
			flag = 0; 
		} 

		// If flag is zero print nodes 
		// from left to right 
		else if (flag == 0) { 
			Print_Level_Left_To_Right(root, i); 

			// Mark flag as one so that next time 
			// nodes are printed from right to left 
			flag = 1; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	struct node* root = newNode(5); 
	root->left = newNode(9); 
	root->right = newNode(3); 
	root->left->left = newNode(6); 
	root->right->right = newNode(4); 
	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(7); 

	PrintReverseZigZag(root); 

	return 0; 
} 
