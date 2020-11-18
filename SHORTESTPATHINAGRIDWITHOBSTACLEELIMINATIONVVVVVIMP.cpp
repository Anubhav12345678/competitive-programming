class Solution {
public:
    struct node{
        int x,y,z;
        node(int _x,int _y,int _z){
            x=_x;
            y=_y;
            z=_z;
        }
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int i,j,l,n,m;
        n = grid.size();
        m = grid[0].size();
        // cout<<"ok";
        vector<vector<vector<int>>> dp(n+10,vector<vector<int>>(m+10,vector<int>(k+10,-1)));
        // memset(dp,-1,sizeof(dp));
        // cout<<"ok";
        queue<node> q;
        q.push({0,0,0});
        dp[0][0][0]=0;
        int ans=n*m;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            node p = q.front();
            int x = p.x;
            int y = p.y;
            int dis = p.z;
            q.pop();
        
            for(i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&(dis+grid[nx][ny])<=k)
                {
                    if(dp[nx][ny][dis+grid[nx][ny]]==-1)
                    {
                        dp[nx][ny][dis+grid[nx][ny]] = dp[x][y][dis]+1;
                        q.push({nx,ny,dis+grid[nx][ny]});
                    }
                }
            }
        }
        
       for(i=0;i<=k;i++){
           if(dp[n-1][m-1][i]!=-1)
               ans = min(ans,dp[n-1][m-1][i]);
       }
        
        if(ans==n*m) return -1;
        return ans;
        
    }
};
/**

Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can
 move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right
 corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).


/