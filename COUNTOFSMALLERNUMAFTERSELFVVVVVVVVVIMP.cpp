class Solution {
public:
    /*
     You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
    */
    struct TreeNode {
      int val,lessthan;
      TreeNode *left;
      TreeNode *right;
      
      TreeNode(int x,int y) : val(x), left(NULL), right(NULL), lessthan(y) {}
  };
    vector<int> countSmaller(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==0)
            return {};
        vector<int> res(n);
        TreeNode* r = NULL;
        for(i=n-1;i>=0;i--)
            r = insert(r,nums[i],i,0,res);
        return res;
    }
    
    TreeNode* insert(TreeNode* root,int val,int ind,int sum,vector<int> &res)
    {
        if(root==NULL)
        {
            res[ind]=sum;
            return new TreeNode(val,0); 
        }
        if(val<root->val)
        {
            root->lessthan++;
            root->left = insert(root->left,val,ind,sum,res);
        }
        else
        {
            if(val!=root->val)
            {
                root->right = insert(root->right,val,ind,sum+root->lessthan+1,res);
            }
            else
                root->right = insert(root->right,val,ind,sum+root->lessthan,res);
        }
        return root;
    }
};