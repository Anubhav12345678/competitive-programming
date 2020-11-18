
/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.



*/


class Solution {
public:
    int solve(vector<int> &v,int l,int r)
    {
        if(l==r)
            return l;
        int m = (l+r)/2;
        if(v[m]>v[m+1])
            return solve(v,l,m);
        return solve(v,m+1,r);
    }
    int findPeakElement(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};