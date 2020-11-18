
/*

Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column. 
 Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
Example 2:

Input: [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
Example 3:

Input: [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.




*/





class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i,j,k,l,ret=1;
        for(int i=0;i<n;i++)
        {
            for(j=0;j<m;j++) 
                if(mat[i][j]==0)
                {
                    for(k=0;k<n;k++)
                        mat[k][j]^=1;
                }
            int sum=0;
            for(j=0;j<n;j++)
            {
                int f=1;
                for(k=1;k<m;k++)
                {
                    if(mat[j][0]!=mat[j][k])
                    {
                        f=0;
                        break;
                    }
                }
                sum+=f;
            }
            ret=max(ret,sum);
        }
        return ret;
    }
};