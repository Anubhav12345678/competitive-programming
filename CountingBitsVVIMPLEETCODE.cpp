
/*

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary
 representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]



*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        int i=0,j,k,l;
        while(i<=n)
        {
            int num=i;
            int cnt=num&1;
            num=num>>1;
            cnt+=dp[num];
            dp[i] = cnt;
            i++;
        }
        return dp;
    }
};