
/*
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
MIN PATH SUM IN A TRIANGLE

*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int i,j,k,l;
        int memo[n];
        for(i=0;i<triangle[n-1].size();i++)
            memo[i] = triangle[n-1][i];
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<triangle[i+1].size()-1;j++)
                memo[j]=min(memo[j],memo[j+1])+triangle[i][j];
        }
        return memo[0];
    }
};