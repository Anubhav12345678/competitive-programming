

/*


Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning,
 each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]




*/




class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int i,j,k,l;
          int maxi=0;
         int dp[555];
        for(i=0;i<555;i++) dp[i]=0;
        for(i=1;i<=n;i++)
        {
            maxi=0;
            for(j=i-1;j>=0;j--)
            {
                maxi= max(maxi,A[j]);
                if(i-j>K)
                    break;
                dp[i] = max(dp[i],dp[j]+maxi*(i-j));
            }
        }
        return dp[n];
    }
};