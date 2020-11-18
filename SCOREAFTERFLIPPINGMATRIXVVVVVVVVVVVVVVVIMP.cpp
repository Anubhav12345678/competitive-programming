class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int i,j,k,l,n=A.size();
        int m = A[0].size();
        int res=0;
        res+=(1<<(m-1))*n;
        for(j=1;j<m;j++){
            int same=0;
            for(i=0;i<n;i++)
            {
                if(A[i][0]==A[i][j])// checking kitne same h 1st col hr row me 1 kr dia
                    same++;
            }
            res+=(1<<(m-1-j))*max(same,n-same);
        }
        return res;
    }
};
/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column:
 changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number,
 and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


*/