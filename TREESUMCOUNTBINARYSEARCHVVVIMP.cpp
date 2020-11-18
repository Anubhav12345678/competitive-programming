#include "solution.hpp"
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
/*
Given a binary tree root and an integer k, return the number of unique node to subchild paths there are which sums to k.

For example, given the following tree with k = 5

   1
  / \
 1   4
    /
   2
    \
     3
Return 2 since there's 1 -> 4 and 2 -> 3.


*/
class Solution {
    public:
    int ans=0;
    int sum=0;
    map<int,int> mp;
    void dfs(Tree* r,int k){
        if(!r) return;
        sum+=r->val;
        if(mp.count(sum-k))
        ans+=mp[sum-k];
        mp[sum]++;
        dfs(r->left,k);
        dfs(r->right,k);
        mp[sum]--;
        if(!mp[sum])
        mp.erase(sum);
        sum-=r->val;
    }
   
    int solve(Tree* root, int k) {
        ans=0;
        mp.clear();
        mp[0]=1;
        sum=0;
        dfs(root,k);
        return ans;
        
        
        // Write your code here
    }
};
