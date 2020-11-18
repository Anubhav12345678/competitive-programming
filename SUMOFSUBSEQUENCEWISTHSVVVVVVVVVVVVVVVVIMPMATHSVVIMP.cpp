#define ll long long
class Solution {
public:
    int mod= 1e9+7;
    int sumSubseqWidths(vector<int>& A) {
        int i,j,k,l,n=A.size();
        sort(A.begin(),A.end());
        ll power[n+1];
        power[0]=1LL;
        for(i=1;i<=n;i++)
            power[i] = (power[i-1]*2)%mod;
        
        ll ans=0LL;
        for(i=0;i<n;i++){
            ans = (ans+(A[i]*(power[i]-power[n-i-1]))%mod)%mod;
        }
        return ans;
    }
};
/*
https://massivealgorithms.blogspot.com/2018/11/leetcode-891-sum-of-subsequence-widths.html
Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.



*/