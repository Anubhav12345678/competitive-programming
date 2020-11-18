/*
Problem Description

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1
 then ithnode is good else if A[i] is 0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf
 paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.
*/

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<vector<int>> adj(n+1);
    vector<int> good(n+1,0);
    for(auto e:B){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    good[1]=A[0];
    int ans=0;
    queue<int> q;
    q.push(1);
    vector<bool> vis(n+1,false);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = true;
        int previousize = q.size();
        for(auto y:adj[node]){
            if(!vis[y])q.push(y);
            good[y] = good[node]+A[y-1];
        }
        // first cond to check isleaf
        if(previousize==q.size()&&good[node]<=C) ans++;
    }
    
    return ans;
}
