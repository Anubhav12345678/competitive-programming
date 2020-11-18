/**
 
  Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the 
row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print
 the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the 
 right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything 
 for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none,
  then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]



 */
class Solution {
public:
    int height(TreeNode* r)
    {
        if(!r)
            return 0;
        return 1+max(height(r->left),height(r->right));
    }
    void solve(vector<vector<string>> &res,int l,int r,int st,TreeNode* root,int h)
    {
        if(l>r||!root||st>=h)
            return;
        int mid = (l+r)/2;
        res[st][mid] = to_string(root->val);
        solve(res,l,mid-1,st+1,root->left,h);
        solve(res,mid+1,r,st+1,root->right,h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if(!root)
            return res;
        int h = height(root);
        res = vector<vector<string>>(h,vector<string>((1<<h)-1,""));
        cout<<res.size()<<" "<<res[0].size()<<endl;
        int n = 1<<h;
        int l=0,r=n-1;
        solve(res,l,r,0,root,h);
        return res;
        
    }
};