// e=when tree is given in edges format
#include<bits/stdc++.h>
using namespace std;
// #define ll long long
#include<vector>
#define pb push_back
#include<queue>
const int maxn = 100001;
struct tmp{
  int i,d;
};
vector<tmp> v[maxn];
int vis[maxn];
int dis[maxn];

int n,m;
int bfs(int s){
    int i,j,k;
    for(i=0;i<maxn;i++)
    {
        vis[i]=0;
        dis[i]=0;
    }
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(i=0;i<(int)v[x].size();i++){
            if(vis[v[x][i].i]==0){
                vis[v[x][i].i]=1;
                dis[v[x][i].i]+=dis[x]+v[x][i].d;
                q.push(v[x][i].i);
            }
        }
    }

    return int(max_element(dis+1,dis+n+1)-dis);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n-1;i++){
            int x,y,w;
            cin>>x>>y>>w;
            struct tmp temp;
            temp.i = y;
            temp.d = w;
            v[x].pb(temp);
            temp.i = x;
            v[y].pb(temp);
        }

        int st = bfs(1);
        int ans = bfs(st);
        int finalans = dis[ans];
        int money = 0;
        if (finalans>100)
            money = 100;
        if (finalans>1000)
            money = 1000;
        if (finalans>10000)
            money = 10000;
        printf("%d %d\n",money,finalans);
    }
}




















/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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
    // int ans=0;
    int res=0;
    int solve(TreeNode* r)
    {
        if(!r)
            return 0;
        int left = solve(r->left);
        int right = solve(r->right);
        int temp = max(left,right)+1;
        int ans = max(temp,left+right+1);
        res = max(res,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return max(res-1,0);
    }
};




















int height(Node *n)
{
    if(n==NULL)
    return 0;
    return 1+max(height(n->left),height(n->right));
}
int diameter(Node* node)
{
    if(node==NULL)
    return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return max(1+lh+rh,max(diameter(node->left),diameter(node->right)));
    
   // Your code here
}

//me leetcode
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
    int ans;
    int dep(TreeNode *r)
    {
       if(!r)
           return 0;
        int l = dep(r->left);
        int right = dep(r->right);
        ans = max(ans,l+right+1);
        return max(l,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;
        dep(root);
        return ans-1;
    }
};



