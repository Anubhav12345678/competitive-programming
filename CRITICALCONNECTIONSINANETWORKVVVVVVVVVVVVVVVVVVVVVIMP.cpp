/*
There are n servers numbered from 0 to n-1 connected by undirected server-to-server
 connections forming a network where connections[i] = [a, b] represents a connection
  between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/
#define INF 0x3f3f3f3f
class Solution {
public:
    
    vector < vector <int> > adj, bridges;
    vector <bool> visited; 
    
    vector <int> disc, low;
    
    void dfs(int u, int parent)
    {
        static int tim = 1;
        disc[u] = low[u] = tim++;
        int child = 0;
        visited[u] = true;
        
        for(auto ele: adj[u])
        {
            if(!visited[ele])
            {
                child++;
                dfs(ele, u);
                low[u] = min(low[u], low[ele]);
                if(low[ele] > disc[u])
                {
                    vector <int> temp;
                    temp.push_back(u);
                    temp.push_back(ele);
                    bridges.push_back(temp);
                }
            }
            else if (ele != parent)
            {
                low[u] = min(low[u], disc[ele]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
                
        visited.resize(n, false);
        disc.resize(n, INF);
        low.resize(n, INF);
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
                
        return bridges;
    }
};