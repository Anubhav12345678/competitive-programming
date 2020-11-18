// C++ program to traverse an N-ary tree 
// without recursion 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of a node of an n-ary tree 
struct Node { 
	char key; 
	vector<Node*> child; 
}; 

// Utility function to create a new tree node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	return temp; 
} 

// Function to traverse tree without recursion 
void traverse_tree(struct Node* root) 
{ 
	// Stack to store the nodes 
	stack<Node*> nodes; 

	// push the current node onto the stack 
	nodes.push(root); 

	// loop while the stack is not empty 
	while (!nodes.empty()) { 

		// store the current node and pop it from the stack 
		Node* curr = nodes.top(); 
		nodes.pop(); 

		// current node has been travarsed 
		cout << curr->key << " "; 

		// store all the childrent of current node from 
		// right to left. 
		vector<Node*>::iterator it = curr->child.end(); 

		while (it != curr->child.begin()) { 
			it--; 
			nodes.push(*it); 
		} 
	} 
} 
// Driver program 
int main() 
{ 
	/* Let us create below tree 
*		 A 
*	 / / \ \ 
*	 B F D E 
*	 / \	 | /|\ 
*	 K J	 G C H I 
* / \		 | | 
* N M	 O L 
*/

	Node* root = newNode('A'); 
	(root->child).push_back(newNode('B')); 
	(root->child).push_back(newNode('F')); 
	(root->child).push_back(newNode('D')); 
	(root->child).push_back(newNode('E')); 
	(root->child[0]->child).push_back(newNode('K')); 
	(root->child[0]->child).push_back(newNode('J')); 
	(root->child[2]->child).push_back(newNode('G')); 
	(root->child[3]->child).push_back(newNode('C')); 
	(root->child[3]->child).push_back(newNode('H')); 
	(root->child[3]->child).push_back(newNode('I')); 
	(root->child[0]->child[0]->child).push_back(newNode('N')); 
	(root->child[0]->child[0]->child).push_back(newNode('M')); 
	(root->child[3]->child[0]->child).push_back(newNode('O')); 
	(root->child[3]->child[2]->child).push_back(newNode('L')); 

	traverse_tree(root); 

	return 0; 
} 
// pstorder n-arr tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        stack<Node*> st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            Node* tmp = st1.top();
            st2.push(tmp);
            st1.pop();
            auto it = tmp->children.begin();
            while(it!=tmp->children.end())
            {
                st1.push(*it);
                it++;
            }
        }
        vector<int> res;
        while(!st2.empty())
        {
            Node* tmp = st2.top();
            res.push_back(tmp->val);
            st2.pop();
        }
        return res;
    }
};