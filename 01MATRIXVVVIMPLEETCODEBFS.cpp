
/*

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i,j,k,l;
        queue<pair<int,int>> q;
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[]= {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                int nx = p.first+dx[i];
                int ny = p.second+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m)
                {
                    if(res[nx][ny]>res[p.first][p.second]+1)
                    {
                        res[nx][ny]=res[p.first][p.second]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return res;
    }
};