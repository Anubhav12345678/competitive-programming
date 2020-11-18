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

We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output
 the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.

 

Example 1:



Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:



Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
 

Example 3:



Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]



*/
class Solution {
public:
    int n;
    TreeNode* solve(string &s,int &i,int dep)
    {
        int x=0;
        for(;i<n&&s[i]!='-';i++) x=x*10+(s[i]-'0');
        TreeNode* p = new TreeNode(x);
        int j,k,l,cnt=0;
        for( j=i;j<n&&s[j]=='-';j++) cnt++;
        if(cnt==dep+1)
        {
            i=j;
            p->left=solve(s,i,dep+1);
        }
        cnt=0;
        for( j=i;j<n&&s[j]=='-';j++) cnt++;
        if(cnt==dep+1)
        {
            i=j;
            p->right=solve(s,i,dep+1);
        }
        return p;
        
    }
    TreeNode* recoverFromPreorder(string s) {
        n = s.size();
        int i=0;
        TreeNode* p = solve(s,i,0);
        return p;
    }
};