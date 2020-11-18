class Solution {
public:
    /*

Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of
 the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you
 can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it
  has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is 
invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

 

Example 1:



Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

    */
    int seen[505][505];
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int n,m;
    vector<vector<char>> g;
    bool solve(int x,int y,int a,int b){
        if(seen[x][y]==2) return false;
        if(seen[x][y]==1) return  true;
        seen[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(g[x][y]!=g[nx][ny]) continue;
            if(nx==a&&ny==b) continue;
            if(solve(nx,ny,x,y)) return true;
        }
        
        seen[x][y] = 2;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        g=grid;
        n=g.size();
        m = g[0].size();
        memset(seen,0,sizeof(seen));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!seen[i][j])
                    if(solve(i,j,-1,-1)) return true;
            }
        }
        return false;
    }
};