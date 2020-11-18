class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int i,j,k,l,n = A.size();
        vector<int> sum(n+1,0);
        for(i=0;i<n;i++){
            sum[i+1] = sum[i]+A[i];
        }
        if(K>=n)
            return (double)sum[n];
        if(k==1)
            return (1.0*(sum[n]))/n;
        vector<vector<double>> dp(n+1,vector<double>(K+1,0.0));
        for(i=1;i<=n;i++){
            dp[i][1] = (1.0*sum[i])/(i);
        }
        
        
        for(k=2;k<=K;k++){
            for(i=k;i<=n;i++){
                for(j=i-1;j>=k-1;j--){
                    dp[i][k] = max(dp[i][k],dp[j][k-1]+(1.0*(sum[i]-sum[j]))/(i-j));
                }
            }
        }
        
        return dp[n][K];
        
        
    }
};
/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average
 of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


*/