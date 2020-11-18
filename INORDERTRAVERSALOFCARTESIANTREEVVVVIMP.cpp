
/*

Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 


*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int segtree[100005];
int buildtree(int l,int r,int i,vector<int> &v)
{
    if(l>r)
    return -1;
    if(l==r)
    {
        segtree[i]=l;
        return l;
    }
    int l1 = buildtree(l,(l+r)/2,2*i+1,v);
    int r1 = buildtree((l+r)/2+1,r,2*i+2,v);
    if(v[l1]>v[r1])
    segtree[i]=l1;
    else
    segtree[i] = r1;
    return segtree[i];
}
int qmax(int l,int r,int ql,int qr,int i,vector<int> &v)
{
    if(l>qr||r<ql)
    return -1;
    if(ql<=l&&qr>=r)
    return segtree[i];
    int l1 = qmax(l,(l+r)/2,ql,qr,2*i+1,v);
    int r1 = qmax((l+r)/2+1,r,ql,qr,2*i+2,v);
    if (l1 == -1) 
        return r1; 
    if (r1 == -1) 
        return l1;
    if(v[l1]>v[r1])
    return l1;
    else
    return r1;
}
TreeNode* create(vector<int> &v,int l,int r,int n)
{
    if(l>r)
    return nullptr;
    // int n=A.size();
    int m = qmax(0,n-1,l,r,0,v);
    TreeNode* cur = new TreeNode(v[m]);
    cur->left = create(v,l,m-1,n);
    cur->right = create(v,m+1,r,n);
    return cur;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    memset(segtree,-1,sizeof(segtree));
    int n = A.size();
    buildtree(0,n-1,0,A);
    return create(A,0,n-1,n);
}
