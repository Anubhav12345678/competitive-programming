class Solution {
public:
    int memo[25][2010];
    int solve(vector<int> &v,int ind,int sum,int S){
        if(ind==v.size())  return sum==S;
        if(memo[ind][sum+1000]!=-1) return memo[ind][sum+1000];
        int add = solve(v,ind+1,sum+v[ind],S);
        int sub = solve(v,ind+1,sum-v[ind],S);
        memo[ind][sum+1000] = add+sub;
        return memo[ind][sum+1000];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,0,S);
    }
};
/*

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

*/