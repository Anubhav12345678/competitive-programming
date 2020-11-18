class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,k,l,n=matrix.size();
        int m = matrix[0].size();
        bool iscol=false;
        for(i=0;i<n;i++){
            if(matrix[i][0]==0)
                iscol=1;
            for(j=1;j<m;j++)
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
        }
        
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                // matrix[i][j]
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        if(matrix[0][0]==0)
            for(i=0;i<m;i++)
                matrix[0][i]=0;
        if(iscol)
            for(i=0;i<n;i++)
                matrix[i][0]=0;
    }
};
/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/