class Solution {
public:
    // vector<vector<int>> adj;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int i,j,k,l,m;
        // adj.resize(n);
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        // vector<vector<bool>>
        int ans=0;
        vector<int> deg(n,0);
        for(auto e:roads)
        {
            deg[e[0]]++;
            deg[e[1]]++;
            vis[e[0]][e[1]] = vis[e[1]][e[0]]=1;
        }
        for(i=0;i<n;i++)
        {
           for(j=i+1;j<n;j++)
           {
               ans = max(ans,deg[i]+deg[j]-vis[i][j]);
           }
        }
                                  return ans;
        // return dfs(0,-1);
        
        
    }
};
/*
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

 

Example 1:



Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only coun




*/