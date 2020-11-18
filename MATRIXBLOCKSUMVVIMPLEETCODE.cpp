
/*
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c]
 for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]




*/



class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int i,j,l;
        vector<vector<int>> res(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m));
        for(i=0;i<n;i++)
            ans[i][0]= mat[i][0];
        for(i=0;i<n;i++)
            for(j=1;j<m;j++)
                ans[i][j] = ans[i][j-1]+mat[i][j];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int c1 = ((j-k)>=0)?(j-k):0;
                int c2 = ((j+k)<m)?(j+k):(m-1);
                for(l=max(0,i-k);l<=min(n-1,i+k);l++)
                {
                    res[i][j]+=(c1>0)?(ans[l][c2]-ans[l][c1-1]):(ans[l][c2]);
                }
            }
        }
        return res;
        
    }
};