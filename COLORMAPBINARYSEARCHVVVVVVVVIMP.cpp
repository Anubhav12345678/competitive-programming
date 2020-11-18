#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<vector<int>> g;
    int n,m;
    void dfs(int i,int j,int col)
    {
        if(i<0||i>=n||j<0||j>=m||g[i][j]!=col)
        return;
        g[i][j]=-1;
        dfs(i-1,j,col);
        dfs(i+1,j,col);
        dfs(i,j-1,col);
        dfs(i,j+1,col);
    }
    int solve(vector<vector<int>>& matrix) {
          n = matrix.size();
          if(n==0) return 0;
          m = matrix[0].size();
          if(m==0) return 0;
          int i,j,k,l;
          int ans=0;
         g=matrix;
         map<int,int> mp;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 if(g[i][j]!=-1)
                 {
                     mp[g[i][j]]++;
                     dfs(i,j,g[i][j]);
                    //  ans++;
                     
                 }
             }
         }
         int mx=0,s=0;
         for(auto it = mp.begin();it!=mp.end();it++)
         {
             int i  = it->first;
             s+=it->second;
             if(it->second>mx)
             mx = it->second;
         }
        //  return ans-1;
        return s-mx;
    }
};
/*
You are given a two-dimensional list of integers matrix. Each cell's value represents its color and adjacent cells (top, bottom, left, right) with the same color are considered to be in the same group.

Consider an operation where we set all cells in one group to some color. Return the minimum number of operations required so that every cell has the same color. Once the color is transformed, it cannot be set again.

Example 1
Input

matrix = [
    [1, 1, 1, 1],
    [2, 2, 2, 2],
    [1, 3, 1, 2]
]
Output

2

*/