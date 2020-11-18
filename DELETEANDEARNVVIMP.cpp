/*

THIS IS SIMILAR TO ROBBER PROB
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
*/

class Solution {
public:
    int maxsumithoutadj(vector<int> &v)
    {
        int i,j,k,l,n=v.size();
        if(n==0) return 0;
        if(n==1) return v[0];
        int dp1=0,dp2=0,dp;
        for(i=0;i<v.size();i++)
        {
            dp = max(dp2+v[i],dp1);
            dp2=dp1;
            dp1=dp;
        }
        return dp1;
    }
    int deleteAndEarn(vector<int>& nums) {
        // if(n==0)
        //     return 0;
        int r,i,j,k,l,n=nums.size();
        if(n==0)
            return 0;
        l = *min_element(nums.begin(),nums.end());
        r = *max_element(nums.begin(),nums.end());
        vector<int> cnt(r-l+1,0);
        for(auto it:nums)
            cnt[it-l]+=it;
        
            // cout<<cnt[i]<<" ";
        return  maxsumithoutadj(cnt);
    }
};

















class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     map<int,int> mp;
        for(auto num: nums)
            if(num) mp[num]+=num;
        int present=INT_MIN,ans=0,pre1=0,pre2=0;
        for(auto it: mp)
        {
            int key = it.first;
            int val = it.second;
            if(key>present+1)
                ans = pre1+val;
            else
                ans = max(pre1,pre2+val);
            pre2=pre1;
            pre1=ans;
            present=key;
        }
        return ans;
    }
};