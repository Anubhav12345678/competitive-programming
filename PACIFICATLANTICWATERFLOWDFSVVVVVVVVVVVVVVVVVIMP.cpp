
/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a
 continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic
  ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one 
with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/
class Solution {
public:
    int n,m;
    void dfs(vector<vector<int> > &g,vector<vector<int>> &vis,int i,int j){
        if(i<0||j<0||i>=n||j>=m||vis[i][j]) return;
        vis[i][j]=true;
        if(i-1>=0&&!vis[i-1][j]&&g[i-1][j]>=g[i][j])
            dfs(g,vis,i-1,j);
        if(i+1<n&&!vis[i+1][j]&&g[i+1][j]>=g[i][j])
            dfs(g,vis,i+1,j);
        if(j-1>=0&&!vis[i][j-1]&&g[i][j-1]>=g[i][j])
            dfs(g,vis,i,j-1);
        if(j+1<m&&!vis[i][j+1]&&g[i][j+1]>=g[i][j])
            dfs(g,vis,i,j+1);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        n=matrix.size();
        if(n==0) return res;
        m =matrix[0].size();
        if(m==0) return res;
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            dfs(matrix,pac,i,0);
            dfs(matrix,atl,i,m-1);
        }
        
        for(int j=0;j<m;j++)
        {
            dfs(matrix,pac,0,j);
            dfs(matrix,atl,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]&&atl[i][j])
                    res.push_back({i,j});
            }
        }
        
        return res;
        
    }
};