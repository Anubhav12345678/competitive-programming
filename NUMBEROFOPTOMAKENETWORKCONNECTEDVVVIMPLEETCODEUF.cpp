
/*

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where
 connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or 
 indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place
 them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do
  this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.




*/



    class Solution {
    public:
        int par[100005];
        // union find
        int find(int a)
        {
            if(a==par[a])
                return par[a];
            return par[a]=find(par[a]);
        }
        int makeConnected(int n, vector<vector<int>>& c) {
            int m = c.size();
            if(m<n-1)
                return -1;
            int i,j,k,l;
            int ans=n-1;
            for(i=0;i<n;i++)
                par[i]=i;
            for(auto it: c)
            {
                int ta = find(it[0]);
                int tb = find(it[1]);
                if(ta!=tb)
                {
                    ans--;
                    par[ta]=tb;
                }
            }
            return ans;
        }
    };