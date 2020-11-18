/*

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].


*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int i,j,l,n=nums.size();
        vector<int> dp(n,0);
        deque<int> q;
        q.push_back(0);
        dp[0]=nums[0];
        int ans=INT_MIN;
        ans = max(ans,dp[0]);
        for(i=1;i<n;i++)
        {
            dp[i] = max(0,dp[q.front()])+nums[i];
            ans=  max(ans,dp[i]);
            while(!q.empty()&&q.front()<=i-k)
                q.pop_front();
            while(!q.empty()&&dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};