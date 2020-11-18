#include "solution.hpp"
using namespace std;

/*
Given a list of integers nums and an integer k, return the length of the longest
 increasing subsequence with at least k odd numbers.

Constraints

k ≤ n ≤ 100 where n is the length of nums.
Example 1


*/
class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        
    if (nums.size() == 0) {
        return 0; 
    }
    vector<vector<int> > dp(nums.size(), vector<int>(k + 1, 0)); 
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] %2 == 0) {
            dp[i][0] = 1; 
        } else {
            dp[i][min(1, k)] = 1; 
            
        }
    }
    
    for (int i = 1; i < nums.size(); ++i) {
        int add = (nums[i]%2==1)?1:0; 
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                
                for (int o = 0; o <= k; ++o) {
                    if (dp[j][o] != 0) {
                        int idx = min(k, o + add); 
                        dp[i][idx] = max(dp[i][idx], dp[j][o] + 1); 
                    }
                }
            }
        }
        
    }
    
    int ans = 0; 
    for (int i = 0; i < nums.size(); ++i) {
        if (dp[i][k] > ans) {
            ans = dp[i][k]; 
        }
    }
    return ans; 
    }
};
