#include "solution.hpp"
using namespace std;
int dp[100005];
class Solution {
    public:
    int fun(int ind,vector<int> &v)
    {
        if(ind==v.size()) return 1;
        else if(ind>v.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pos=0;
        if(ind+1<v.size()&&v[ind]==v[ind+1])
        pos|=fun(ind+2,v);
        if(ind+2<v.size()&&v[ind]==v[ind+1]&&v[ind+1]==v[ind+2])
        pos|=fun(ind+3,v);
        if(ind+2<v.size()&&(v[ind]==(v[ind+1]-1))&&(v[ind+1]==(v[ind+2]-1)))
        pos|=fun(ind+3,v);
        return dp[ind]=pos;
    }
    bool solve(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,nums);
    }
};
/*
Given a list of integers nums, return whether every number can be grouped using one of the following rules:

You can form contiguous pairs (a, a)
You can form contiguous triplets (a, a, a)
You can form contiguous triplets (a, a + 1, a + 2)
Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input

nums = [7, 7, 3, 4, 5]
Output

true


*/