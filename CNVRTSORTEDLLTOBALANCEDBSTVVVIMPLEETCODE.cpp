/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every
 node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5



*/
class Solution {
public:
    ListNode* h;
    int nonode(ListNode* head)
    {
        if(!head)
            return 0;
        return 1+nonode(head->next);
    }
    TreeNode* solve(int l,int r)
    {
        if(l>r||h==NULL)
            return NULL;
        int mid= (l+r)/2;
        TreeNode* left = solve(l,mid-1);
        TreeNode* root  = new TreeNode(h->val);
        h=h->next;
        root->left = left;
        TreeNode* right = solve(mid+1,r);
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n= nonode(head);
        h=head;
        return solve(0,n-1);
    }
};