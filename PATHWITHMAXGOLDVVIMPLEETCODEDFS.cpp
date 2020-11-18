

/*

In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 
0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.




*/



class Solution {
public:
    int dfs(vector<vector<int>> &g,int row,int col)
    {
               int dx[] = {1,-1,0,0};
               int dy[] = {0,0,1,-1};
        int n = g.size();
        int m = g[0].size();
       int ans=0;
        int tmp = g[row][col];
        g[row][col]=0;
        for(int i=0;i<4;i++)
        {
            int nx = row+dx[i];
            int ny = col+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny])
                ans = max(ans,dfs(g,nx,ny));
        }
        g[row][col]=tmp;
        return g[row][col]+ans;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int i,j,k,l;
        int m = grid[0].size();
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    // int res = dfs(grid,i,j);
                    // cout<<"res=  "<<res<<endl;
                    ans = max(ans,dfs(grid,i,j));
                    // cout<<"i = "<<i<<"j = "<<j<<"ans = "<<ans<<endl;
                }
            }
        }
        return ans;
        
        
    }
};