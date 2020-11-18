// static int N = 5e4+10; 
/*

There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two 
different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads
 in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach the city 0 after reorder.

 

Example 1:



Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).



*/

class Solution {
public:
    vector<pair<int,int>> v[50010];
    int ret=0;
    void dfs(int u,int par)
    {
        for(auto& [a,b]: v[u])
        {
            if(a==par) continue;
            ret+=b;
            dfs(a,u);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int i,j,k,l;
        for(auto it:connections)
        {
            v[it[0]].push_back({it[1],1});
            v[it[1]].push_back({it[0],0});
        }
        ret=0;
        dfs(0,-1);
        return ret;
    }
};