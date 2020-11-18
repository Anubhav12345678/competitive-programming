class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int i,j,k,l,m;
        vector<vector<pair<int,int>>> g(n);
        for(auto it:red_edges) g[it[0]].push_back({it[1],0});
        for(auto it:blue_edges) g[it[0]].push_back({it[1],1});
        // 0 for red 
        // 1 for blue
        vector<vector<int>> vcost(n,vector<int>(2,-1));
        // vcost[i][0] cost to reach node with last edge as red
        // vcost[i][1] cost to reach node with last edge as blue
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        vcost[0] = {0,0};
        while(!q.empty()){
            auto [i,c1] = q.front();
            q.pop();
            for(auto [j,c2]:g[i]){
                if(vcost[j][c2]!=-1||c1==c2) continue;
                vcost[j][c2] = 1+vcost[i][c1];
                q.push({j,c2});
            }
        }
        vector<int> ans(n);
        k=0;
        for(auto &v:vcost){
            sort(v.begin(),v.end());
            ans[k++] = (v[0]!=-1)?v[0]:v[1];
        }
        return ans;
        
    }
};
/*
Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge 
is either red or blue, and there could be self-edges or parallel edges.

Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j]
 in blue_edges denotes a blue directed edge from node i to node j.

Return an array answer of length n, where each answer[X] is the length of the shortest path from node
 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

 

Example 1:

Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
Output: [0,1,-1]



*/