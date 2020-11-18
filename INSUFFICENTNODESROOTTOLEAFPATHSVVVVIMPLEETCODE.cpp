
/*

Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.
  (A leaf is a node with no children.)

A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.

Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

 




*/






class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
       if (root == nullptr) {
      return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root->val < limit ? nullptr : root;
    }
    root->left = sufficientSubset(root->left, limit - root->val);
    root->right = sufficientSubset(root->right, limit - root->val);
    return root->left == root->right ? nullptr : root;
    }
};