// CPP program to check if all leaf nodes are at 
// same level of binary tree 
#include <bits/stdc++.h> 
using namespace std; 

// tree node 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// returns a new tree Node 
Node* newNode(int data) 
{ 
	Node* temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// return true if all leaf nodes are 
// at same level, else false 
int checkLevelLeafNode(Node* root) 
{ 
	if (!root) 
		return 1; 

	// create a queue for level order traversal 
	queue<Node*> q; 
	q.push(root); 

	int result = INT_MAX; 
	int level = 0; 

	// traverse until the queue is empty 
	while (!q.empty()) { 
		int size = q.size(); 
		level += 1; 

		// traverse for complete level 
		while(size > 0){ 
			Node* temp = q.front(); 
			q.pop(); 
		
			// check for left child 
			if (temp->left) { 
				q.push(temp->left); 

				// if its leaf node 
				if(!temp->left->right && !temp->left->left){ 

					// if it's first leaf node, then update result 
					if (result == INT_MAX) 
						result = level; 
					
					// if it's not first leaf node, then compare 
					// the level with level of previous leaf node 
					else if (result != level) 
						return 0;					 
				} 
			} 
			
			// check for right child 
			if (temp->right){ 
				q.push(temp->right); 

				// if it's leaf node 
				if (!temp->right->left && !temp->right->right) 

					// if it's first leaf node till now, 
					// then update the result 
					if (result == INT_MAX) 
						result = level; 
					
					// if it is not the first leaf node, 
					// then compare the level with level 
					// of previous leaf node 
					else if(result != level) 
						return 0; 
					
			} 
			size -= 1; 
		}	 
	} 
	
	return 1; 
} 

// driver program 
int main() 
{ 
	// construct a tree 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->right = newNode(4); 
	root->right->left = newNode(5); 
	root->right->right = newNode(6); 

	int result = checkLevelLeafNode(root); 
	if (result) 
		cout << "All leaf nodes are at same level\n"; 
	else
		cout << "Leaf nodes not at same level\n"; 
	return 0; 
} 
