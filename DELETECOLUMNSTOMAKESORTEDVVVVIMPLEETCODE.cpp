/*
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["babca","bbazb"] and deletion indices {0, 1, 4}, then the final array after deletions is 
["bc","az"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has every element (row) in lexicographic 
order.

For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in lexicographic order
 (ie. A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.

Return the minimum possible value of D.length.

 

Example 1:

Input: ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.



*/



class Solution {
public:

    int minDeletionSize(vector<string>& A) {
        int i,j,k,l,n=A[0].size(),m=A.size();
        int ans=1e9+7;
        int dp[n];
        memset(dp,1,sizeof(dp));
        for(i=0;i<n;i++)
            dp[i]=1;
        int maxi=1;
        for(i=1;i<n;i++)
        {
           for(j=0;j<i;j++)
           {
               bool f=1;
               for(k=0;k<m;k++)
                   if(A[k][j]>A[k][i])
                   {
                       f=0;
                       break;
                   }
               if(f)
               {
                   dp[i]=max(dp[i],dp[j]+1);
                   maxi=max(maxi,dp[i]);
               }
           }
        }
        for(i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<"n="<<n<<" "<<maxi<<endl;
        return n-maxi;
    }
};