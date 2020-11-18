class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum=0;vector<int>right,top;
        int n=grid.size();
        for(int i=0 ; i<n ; i++) right.push_back(*max_element(grid[i].begin(),grid[i].end()));
        for(int i=0 ; i<n ; i++)
        {
            int maxm=grid[0][i];
            for(int j=0 ; j<n ; j++) if(grid[j][i]>maxm)maxm=grid[j][i];
            top.push_back(maxm);
        }
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                sum+=abs(grid[i][j]-min(top[j],right[i]));
        return sum;
    }
};