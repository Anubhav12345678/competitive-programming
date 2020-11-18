//DFS SOL
/*
Normally, we would run breadth-first search from each cell simultaneonly, tracking water cells we
 visited. Sort of like Dijkastra’s algorithm. However, I wanted to try a depth-first
  search solution, as it seemed easier to implement at the time.

The DFS solution is accepted but has higher runtime complexity, so I then added the BFS solution to compare.

DFS Solution
For each 'land' cell, start DFS and record the distance in 'water' cells.

If the distance in the 'water' cell is smaller than the current distance, we stop there. 
Otherwise, we update the distance to the smaller value and keep going.

So our grid will have the following values:

1 for land
0 for water
>=2 water with the recorded distance
In the end, we scan the grid again and returning the largest value.

In this example, the cells contains distances after DFS is complete for each land cell. 
In the end, the maximum distance from the land is 3 (4 - 1).

*/
class Solution {
public:
    void dfs(int i,int j,int n,vector<vector<int>> &g,int dis=1){
        if(i<0||j<0||i>=n||j>=n||(g[i][j]!=0&&g[i][j]<=dis)) return;
        g[i][j] = dis;
        dfs(i+1,j,n,g,dis+1);
        dfs(i-1,j,n,g,dis+1);
        dfs(i,j+1,n,g,dis+1);
        dfs(i,j-1,n,g,dis+1);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int i,j,k,l,n=grid.size();
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    dfs(i,j,n,grid);
                }
            }
        }
        
        // int mx=INT_MIN;
        int mx=-1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
              if(grid[i][j]>1)  mx = max(mx,grid[i][j]-1);
            }
        }
        return mx;
    }
};
//https://leetcode.com/problems/as-far-from-land-as-possible/discuss/360963/C%2B%2B-with-picture-DFS-and-BFS
//BFS SOL

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid,int steps=0) {
        int i,j,k,l,n=grid.size();
        queue<pair<int,int>> q,q1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i+1,j}),q.push({i-1,j}), q.push({i,j+1}), q.push({i,j-1});
            }
        }
        while(!q.empty()){
            ++steps;
            // hmari current level ko process krne k liye
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>=0&&y>=0&&x<n&&y<grid[x].size()&&grid[x][y]==0){
                    grid[x][y]=steps;
                    q1.push({x+1,y}),q1.push({x-1,y}), q1.push({x,y+1}), q1.push({x,y-1});
                }
            }
            swap(q1,q);
        }
        // cout<<
        return (steps==1)?-1:steps-1;
    }
};
