class Solution {
public:
    bool isval(int i,int j,int n,int m)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    int surfaceArea(vector<vector<int>>& grid) {
        int i,j,k,l,n=grid.size();
        int m = grid[0].size();
        // if(n==1&&m==1)
        //     return ;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<"i = "<<i<<" j = "<<j<<"cnt = "<<cnt<<endl;
                if(grid[i][j]>0)
                {
                    cnt+=2;
                    for(k=0;k<4;k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        int nv=0;
                        if(isval(nx,ny,n,m))
                            nv = grid[nx][ny];
                        cnt+=max(grid[i][j]-nv,0);
                        cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<"cnt = "<<cnt<<endl;
                    }
                }
            }
        }
        return cnt;
    }
};