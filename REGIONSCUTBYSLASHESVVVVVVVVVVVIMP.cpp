class Solution {
public:
    vector<vector<int>> g;
    int n,m;
    void dfs(int i,int j)
    {
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]==1) return;
        g[i][j]=1;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }
    int regionsBySlashes(vector<string>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        g.resize(n*3,vector<int>(m*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='/')
                {
                    g[i*3][j*3+2] = g[i*3+1][j*3+1] = g[i*3+2][j*3]=1;
                }
                if(grid[i][j]=='\\')
                {
                    g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]==0)
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:
REGIONSCUTBYSLASS


*/