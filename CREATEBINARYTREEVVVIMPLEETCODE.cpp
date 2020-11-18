

/*

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.



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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return NULL;
        int maxi=nums[0];
        int st=0,i,j,k=0,l;
        for(i=1;i<n;i++)
        {
            if(maxi<nums[i])
            {
                maxi= nums[i];
                st=i;
            }
        }
        TreeNode* r = new TreeNode(maxi);
        vector<int> cpy(st);
        for(i=0;i<st;i++)
            cpy[k++]=nums[i];
        // copy(nums.begin(),nums.begin()+st-1,cpy.begin());
        r->left = constructMaximumBinaryTree(cpy);
        vector<int> cpy2(n-st-1);
        k=0;
        for(i=st+1;i<n;i++)
        {
            cpy2[k++]=nums[i];
        }
        // copy(nums.begin()+st+1,nums.end(),cpy2.begin());
        r->right =  constructMaximumBinaryTree(cpy2);
        return r;
    }
};