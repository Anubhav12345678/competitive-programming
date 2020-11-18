
/*

Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product 
of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles
 in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.




*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int sum=0;
        int inf = 1e9+7;
        // sort(A.begin(),A.end());
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int len=2;len<n;len++)
        {
            for(i=0;i+len<n;i++)
            {
                j=i+len;
                dp[i][j]=inf;
                for(k=i+1;k<j;k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
            }
        }
        return dp[0][n-1];
    }
};




class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int sum=0;
        int inf = 1e9+7;
        // sort(A.begin(),A.end());
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int gap;
        for(gap=0;gap<n;gap++)
        {
            for(i=0,j=gap;j<n;i++,j++)
            {
                if(j<i+2)
                {
                    dp[i][j]=0;
                    continue;
                }
                    
                dp[i][j]=inf;
                for(k=i+1;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],(dp[i][k]+dp[k][j]+(A[i]*A[j]*A[k])));
                }
            }
        }
        return dp[0][n-1];
    }
};