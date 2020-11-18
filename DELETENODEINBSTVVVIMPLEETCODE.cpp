/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 /*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node
 reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.



 */
class Solution {
public:
    TreeNode* merge(TreeNode* l,TreeNode* r)
    {
        if(l!=NULL)
        {
            TreeNode* cur=l;
            while(cur&&cur->right)
                cur=cur->right;
            cur->right=r;
            return l;
        }
        return r;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val==key)
            return merge(root->left,root->right);
        else if(root->val<key)
            root->right = deleteNode(root->right,key);
        else if(root->val>key)
            root->left = deleteNode(root->left,key);
        return root;
            
    }
};


// /GFG 2d method
// C++ program to demonstrate delete operation in binary search tree 
#include<bits/stdc++.h> 
using namespace std; 

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<< root->key; 
        inorder(root->right); 
    } 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 

    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 

    /* return the (unchanged) node pointer */
    return node; 
} 

/* Given a non-empty binary search tree, return the node with minimum 
key value found in that tree. Note that the entire tree does not 
need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 

    return current; 
} 

/* Given a binary search tree and a key, this function deletes the key 
and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 

    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 

    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 

    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 

        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 

        // Copy the inorder successor's content to this node 
        root->key = temp->key; 

        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
            50 
        /    \ 
        30   70 
        / \ / \ 
    20 40 60 80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 

    cout<<"\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 

    cout<<"\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 

    cout<<"\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 

    return 0; 
} 

// This code is contributed by shivanisinghss2110 
