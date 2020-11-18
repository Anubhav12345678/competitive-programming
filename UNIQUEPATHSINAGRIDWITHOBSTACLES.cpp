class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> v(obstacleGrid.begin(),obstacleGrid.end());
        int m = v.size();
        int n= v[0].size();
        long long int i,j,k,l;
        long long int path[m][n];
        memset(path,0,sizeof(path));
        if(v[0][0]==0)
            path[0][0]=1;
        for(i=1;i<m;i++)
            if(v[i][0]==0)
                path[i][0]=path[i-1][0];
        for(i=1;i<n;i++)
            if(v[0][i]==0)
                path[0][i] = path[0][i-1];
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                if(v[i][j]==0)
                    path[i][j] = path[i-1][j]+path[i][j-1];
        return (int)path[m-1][n-1];
    }
};