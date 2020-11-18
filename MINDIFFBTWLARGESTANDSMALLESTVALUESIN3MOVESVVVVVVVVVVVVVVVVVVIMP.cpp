class Solution {
public:
    int minDifference(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n<=4) return 0;
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(i=0;i<4;i++)
            ans=min(ans,nums[n-4+i]-nums[i]);
        return ans;
    }
    
};
/*
Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.

Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.

 

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.


*/