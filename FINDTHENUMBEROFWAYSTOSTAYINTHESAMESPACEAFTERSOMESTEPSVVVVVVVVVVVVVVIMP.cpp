#define ll long long
ll MOD = 1e9+7;
class Solution {
public:
    vector<vector<ll>> memo;
    ll len;
    ll solve(int i,int steps){
        if(steps==0&&i==0) return 1;
        if(i<0||i>=len||steps<=0||i>steps)
            return 0;
        if(memo[i][steps]!=-1) return memo[i][steps]%MOD;
        ll ans = (solve(i+1,steps-1)%MOD+solve(i-1,steps-1)%MOD+solve(i,steps-1)%MOD)%MOD;
        return memo[i][steps] = ans%MOD;
        
    }
    int numWays(int steps, int arrLen) {
        // pos 0 - n-1
        // num steps left
        memo.resize(steps/2+1,vector<ll>(steps+1,-1));
        len=arrLen;
        return solve(0,steps);
    }
};
/*
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position 
to the right in the array or stay in the same place  (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

*/