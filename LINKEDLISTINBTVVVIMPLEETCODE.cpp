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
class Solution {
public:
    bool checkPath(ListNode *head, TreeNode *root) {
        if (head->val != root->val) return false;
        if (head->next == NULL) return true;
        if (root->left != NULL && checkPath(head->next, root->left)) return true;
        if (root->right != NULL && checkPath(head->next, root->right)) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (checkPath(head, root)) return true;
        if (root->left != NULL && isSubPath(head, root->left)) return true;
        if (root->right != NULL && isSubPath(head, root->right)) return true;
        return false;
    }
};