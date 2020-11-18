class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int i,j,k,l;
        vector<int> dp(n+1,0);
        for(i=2;i<=n;i++)
        {
            dp[i]=i;
            for(k=2;k<i;k++)
                if(i%k==0)
                dp[i] = min(dp[i],dp[k]+i/k);
        }
        return dp[n];
    }
};
/*

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps
     permitted. Output the minimum number of steps to get n 'A'.


*/