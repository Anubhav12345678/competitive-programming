class Solution {
public:
    /*
Given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n 
nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0,
 and each node of the tree has a label which is a lower-case character given in the string 
 labels (i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.


    */
    vector<vector<int>> adj;
    string l;
    vector<int> ans;
    vector<int> cnt;
    void dfs(int u,int p=-1)
    {
        int lc = cnt[l[u]-'a']++;
        for(auto v:adj[u])
        {
            if(v^p)
                dfs(v,u);
        }
        ans[u] = cnt[l[u]-'a']-lc;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector<vector<int>>(n);
        l = labels;
        ans = vector<int>(n);
        cnt = vector<int>(26,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0);
        return ans;
        
    }
};