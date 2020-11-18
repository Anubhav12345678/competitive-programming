/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at
 this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have
  security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can 
rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.




*/


class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int i,j,k,l;
        int res1=0,res2=0;
        int inc1,inc2,exc1=1,exc2;
        inc1 = nums[0];
        inc2= nums[1];
        if(n==2)
            return nums[1]>nums[0]?nums[1]:nums[0];
        exc1 = 0;
        exc2 = 0;
        for(i=1;i<n-1;i++)
        {
            int p = max(inc1,exc1);
            inc1 = exc1+nums[i];
            exc1  =p;
        }
        for(i=2;i<n;i++)
        {
            int p = max(exc2,inc2);
            inc2 = exc2+nums[i];
            exc2=p;
        }
        return max(max(inc1,exc1),max(inc2,exc2));
    }
};