class Solution {
public:
    struct node
    {
      int x,y,k;
        node(int _x,int _y,int _k){ x=_x; y=_y; k=_k;}
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m=grid[0].size();
        int dp[n+10][m+10][k+10];
        memset(dp,-1,sizeof(dp));
        queue<struct node> q;
        dp[0][0][0]=0;
        q.push(node(0,0,0));
        int dx[] = {-1,1,0,0};
        int dy[]= {0,0,1,-1};
        int i,j,l,nx,ny,nk;
        while(!q.empty())
        {
            struct node tmp = q.front();
            q.pop();
            int ux = tmp.x;
            int uy = tmp.y;
            int uk = tmp.k;
            
            for(i=0;i<4;i++)
            {
                
                nx = ux+dx[i];
                ny=uy+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&uk+grid[nx][ny]<=k)
                {
                    if(dp[nx][ny][uk+grid[nx][ny]]==-1)
                    {
                        dp[nx][ny][uk+grid[nx][ny]]=dp[ux][uy][uk]+1;
                        q.push(node(nx,ny,uk+grid[nx][ny]));
                    }
                }
            }
        }
        int ans=n*m;
        for(i=0;i<=k;i++)
        {
            if(dp[n-1][m-1][i]!=-1)
            {
                ans= min(ans,dp[n-1][m-1][i]);
            }
        }
        if(ans==n*m) return -1;
        return ans;
    }
};