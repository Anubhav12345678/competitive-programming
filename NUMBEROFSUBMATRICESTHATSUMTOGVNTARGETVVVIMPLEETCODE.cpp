
/*

Given a matrix, and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different:
 for example, if x1 != x1'.

 

Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.





*/






class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i,j,k,l,I;
        vector<vector<int>> v(n,vector<int>(m,0));
        for(i=0;i<m;i++)
            v[0][i] = matrix[0][i];
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                v[i][j] = v[i-1][j]+matrix[i][j];
            }
        }
        int ans=0;
        for(I=0;I<n;I++)
        {
            for(i=I;i<n;i++)
            {
                map<int,int> mp;
                int cursum=0;
                for(k=0;k<m;k++)
                {
                    cursum+=v[i][k];
                    if(I!=0)
                        cursum-=v[I-1][k];
                    if(cursum==target)
                        ans++;
                    ans+=mp[cursum-target];
                    mp[cursum]++;
                }
            }
        }
        return ans;
    }
};