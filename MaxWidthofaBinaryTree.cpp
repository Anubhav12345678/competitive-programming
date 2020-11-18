// C++ program to calculate width of binary tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
}; 

/*Function protoypes*/
int getWidth(node* root, int level); 
int height(node* node); 
node* newNode(int data); 

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(node* root) 
{ 
	int maxWidth = 0; 
	int width; 
	int h = height(root); 
	int i; 
		
	/* Get width of each level and compare 
		the width with maximum width so far */
	for(i = 1; i <= h; i++) 
	{ 
		width = getWidth(root, i); 
		if(width > maxWidth) 
		maxWidth = width; 
	} 
		
	return maxWidth; 
} 

/* Get width of a given level */
int getWidth(node* root, int level) 
{ 
	
	if(root == NULL) 
		return 0; 
		
	if(level == 1) 
		return 1; 
				
	else if (level > 1) 
		return getWidth(root->left, level - 1) + 
				getWidth(root->right, level - 1); 
} 


/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of 
	nodes along the longest path from the root node 
	down to the farthest leaf node.*/
int height(node* node) 
{ 
	if (node == NULL) 
		return 0; 
	else
	{ 
		/* compute the height of each subtree */
		int lHeight = height(node->left); 
		int rHeight = height(node->right); 
		/* use the larger one */
		
		return (lHeight > rHeight)? (lHeight + 1): (rHeight + 1); 
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
node* newNode(int data) 
{ 
	node* Node = new node(); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 
	return(Node); 
} 

/* Driver code*/
int main() 
{ 
	node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(8); 
	root->right->right->left = newNode(6); 
	root->right->right->right = newNode(7);	 
	
	/* 
	Constructed bunary tree is: 
			1 
			/ \ 
		2 3 
		/ \ \ 
		4 5 8 
				/ \ 
				6 7 
	*/
	cout<<"Maximum width is "<< getMaxWidth(root)<<endl; 
	return 0; 
} 

// This code is contributed by rathbhupendra 


//another sol
#include<bits/stdc++.h>
using namespace std;
#include<queue>
int maxWidth(TreeNode* r)
{
	if(!r)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int n=1;
	int maxnode=1;
	while(!q.empty())
	{
		n = q.size();
		maxnode = max(maxnode,n);
		while(n--)
		{
			TreeNode* tmp = q.front();
			q.pop();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
	}
	return maxWidth
}

// ANOTHER SOL ON LEETCODE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
         int ans = 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        if (root)
            q.push({root, 1});
        
        while (!q.empty()) {
            int cnt = q.size();
            unsigned long long left = q.front().second, right;
            for (int i = 0; i < cnt; i++) {
                TreeNode* n = q.front().first;
                right = q.front().second;
                q.pop();
                if (n->left != nullptr) {
                    q.push({n->left, 2*right});
                }
                if (n->right != nullptr) {
                    q.push({n->right, 2*right+1});
                }
            }
            //cout << right << " " << left << "\n";
            ans = max(ans, (int)(right - left + 1));
        }
        
        return ans;
    }
};





