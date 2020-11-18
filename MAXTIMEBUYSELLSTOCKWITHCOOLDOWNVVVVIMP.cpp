
/*
1. Define States
To represent the decision at index i:
buy[i]: Max profit till index i. The series of transaction is ending with a buy.
sell[i]: Max profit till index i. The series of transaction is ending with a sell.
To clarify:
Till index i, the buy / sell action must happen and must be the last action. It may not happen at index i. It may happen
 at i - 1, i - 2, ... 0.
In the end n - 1, return sell[n - 1]. Apparently we cannot finally end up with a buy. In that case, we would rather take a 
rest at n - 1.
For special case no transaction at all, classify it as sell[i], so that in the end, we can still return sell[n - 1]. 
Thanks @alex153 @kennethliaoke @anshu2.
2. Define Recursion
buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or 
sell at/before i - 2, then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.
sell[i]: To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or
 buy at/before i - 1, then sell at i.
So we get the following formula:
buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);   
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
3. Optimize to O(1) Space
DP solution only depending on i - 1 and i - 2 can be optimized using O(1) space.
Let b2, b1, b0 represent buy[i - 2], buy[i - 1], buy[i]
Let s2, s1, s0 represent sell[i - 2], sell[i - 1], sell[i]
Then arrays turn into Fibonacci like recursion:
b0 = Math.max(b1, s2 - prices[i]);
s0 = Math.max(s1, b1 + prices[i]);
4. Write Code in 5 Minutes
First we define the initial states at i = 0:
We can buy. The max profit at i = 0 ending with a buy is -prices[0].
We cannot sell. The max profit at i = 0 ending with a sell is 0.




*/


O(1) space sol

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int i,j,k,l,n=p.size();
        if(n<=1)
            return 0;
        int b0,b1,b2,s0,s1,s2;
        b1 = -p[0];
        s1=0,s2=0;
        for(i=1;i<=n;i++)
        {
            b0 = max(b1,s2-p[i-1]);
            s0 = max(s1,b1+p[i-1]);
            b1 = b0;
            s2=s1;
            s1=s0;
        }
        return s1;
    }
};


O(N) space sol
class Solution {
public:
    int solve(vector<int> &p){
        // dp[i][0] = we do not have a stock on the ith day means either wew have sold the stock before or we have sold the previous stock today
        // dp[i][1] =  we have the stock today means we are either carry forwarding  orwe purchased on the ith day
        int i,j,k,l,n=p.size();
        if(n<=1) return 0;
        if(n==2&&p[1]>p[0]) return p[1]-p[0];
        else if(n==2) return 0;
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -p[0];
        dp[1][0] = max(dp[0][0],dp[0][1]+p[1]);
        dp[1][1] = max(dp[0][1],dp[0][0]-p[1]);
        for(i=2;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+p[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-2][0]-p[i]);
        }
        
        return dp[n-1][0];
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};