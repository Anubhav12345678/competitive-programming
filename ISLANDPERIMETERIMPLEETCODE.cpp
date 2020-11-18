class Solution {
public:
    int noofneighbour(vector<vector<int>> &mat,int i,int j)
    {
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        if(i>0&&mat[i-1][j])
            cnt++;
        if(j>0&&mat[i][j-1])
            cnt++;
        if(i<n-1&&mat[i+1][j])
            cnt++;
        if(j<m-1&&mat[i][j+1])
            cnt++;
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i,j,k,l;
        int res=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(grid[i][j])
                    res+=(4-noofneighbour(grid,i,j));
        }
        return res;
    }
};