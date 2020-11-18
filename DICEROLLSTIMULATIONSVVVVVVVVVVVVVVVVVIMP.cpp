class Solution {
public:
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(5001,vector<vector<int>>(6,vector<int>(19,-1)));
    int m = 1000000007;
    int dfs(int dieleft,vector<int> &rm,int last,int curlen){
        if(dieleft==0)
        {
            return 1;
        }
        if(last>=0&&dp[dieleft][last][curlen]>0) return dp[dieleft][last][curlen];
        int ans=0;
        for(int i=0;i<6;i++){
            if(i==last&&curlen==rm[i]) continue;
            ans = (ans+dfs(dieleft-1,rm,i,((i==last)?curlen+1:1)))%m;
        }
        if(last>=0) dp[dieleft][last][curlen] = ans;
        return ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        // memset(dp,0,sizeof(dp));
        return dfs(n,rollMax,-1,0);
    }
};
/*
A die simulator generates a random number from 1 to 6 for each roll. You introduced
 a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 

Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

Two sequences are considered different if at least one element differs from each other.
 Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there 
are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers
 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.

*/