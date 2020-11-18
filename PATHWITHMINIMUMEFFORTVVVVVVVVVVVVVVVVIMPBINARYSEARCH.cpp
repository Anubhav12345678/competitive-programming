static int dx[] = {-1,1,0,0};
static    int dy[] = {0,0,-1,1};
class Solution {
public:
    bool vis[105][105];
    int n,m;
    vector<vector<int>> h;
    queue<pair<int,int>> q;
    bool check(int x)
    {
        int i,j,k,l;
        memset(vis,false,sizeof(vis));
        q.push({1,1});
        vis[1][1]=1;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = p.first+dx[i];
                int ny = p.second+dy[i];
                if(nx>0&&nx<=n&&ny>0&&ny<=m)
                {
                    if(!vis[nx][ny]&&abs(h[p.first][p.second]-h[nx][ny])<=x)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
        }
        return vis[n][m];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // h=heights;
        n=heights.size();
        m = heights[0].size();
        h.resize(n+1,vector<int>(m+1));
        // n=h.size();
        // m = h[0].size(/);
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                h[i+1][j+1] = heights[i][j];
        }
        int mi = 0,ma=1e6;
        while(mi<=ma)
        {
            int mid = (mi+ma)>>1;
            if(check(mid)) ma=mid-1;
            else
                mi = mid+1;
        }
        return mi;
        
    }
};
/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.


*?