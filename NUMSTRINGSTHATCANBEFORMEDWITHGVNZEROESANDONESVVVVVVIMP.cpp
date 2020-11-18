class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i,j,k,l,p=strs.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(auto &s:strs){
            int x = count(s.begin(),s.end(),'1');
            int y = s.size()-x;
            for(i=m;i>=y;i--){
                for(j=n;j>=x;j--){
                    dp[i][j] = max(dp[i][j],1+dp[i-y][j-x]);
                }
            }
        }
        return dp[m][n];
    }
};
/*
Given an array, strs, with strings consisting of only 0s and 1s. Also two integers m and n.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1
 can be used at most once.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10","0001","1","0".


*/