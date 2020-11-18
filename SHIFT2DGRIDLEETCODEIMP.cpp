class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
         int n = g.size();
        int m = g[0].size();
        while (k --)
        {
            vector<vector<int>> a = g;
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < m; ++ j)
                {
                    if (i == n-1 && j == m-1)
                        g[0][0] = a[i][j];
                    else if (j == m-1)
                        g[i+1][0] = a[i][j];
                    else
                        g[i][j+1] = a[i][j];
                }
        }
        return g;
    }
};