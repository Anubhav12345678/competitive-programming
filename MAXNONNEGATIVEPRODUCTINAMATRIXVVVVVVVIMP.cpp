#define ll long long

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ll i,j,k,l,n,m;
        n = grid.size();
        m = grid[0].size();
        // first represent min neg pred uptill this point
        // second max prod uptill this point
        ll mod = 1e9+7;
        vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(m));
        dp[0][0].first = dp[0][0].second =  grid[0][0];
        for(i=1;i<m;i++)
            dp[0][i].first = dp[0][i].second = dp[0][i-1].first*grid[0][i];
        for(i=1;i<n;i++)
            dp[i][0].first = dp[i][0].second = dp[i-1][0].first*grid[i][0];
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(grid[i][j]<0){
                    dp[i][j].first = max(dp[i-1][j].second,dp[i][j-1].second)*(ll)grid[i][j];
                    dp[i][j].second = min(dp[i-1][j].first,dp[i][j-1].first)*(ll)grid[i][j];
                }
                else{
                    dp[i][j].first = min(dp[i-1][j].first,dp[i][j-1].first)*(ll)grid[i][j];
                    dp[i][j].second = max(dp[i-1][j].second,dp[i][j-1].second)*(ll)grid[i][j];
                }
                
//                 cout<<"dp["<<i<<"]["<<j<<"].first = "<<dp[i][j].first<<endl;
//                 cout<<"dp["<<i<<"]["<<j<<"].second = "<<dp[i][j].second<<endl;
                
            }
        }
        
        return (dp[n-1][m-1].second<0)?(-1):(dp[n-1][m-1].second%(mod));
    }
};
/*


You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.

Notice that the modulo is performed after getting the maximum product.

 

Example 1:

Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.


*/