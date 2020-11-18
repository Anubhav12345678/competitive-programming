class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int i,j,k,l,n=nums.size();
        set<int> st;
        st.insert(0);
        int x=0,ans=0;
        for(auto v:nums){
            x+=v;
            if(st.find(x-target)!=st.end()){
                ans++;
                st.clear();// piche ki hr memory vanish kr rhe h as non overlapping subarray cahiye.
            }
            st.insert(x);
        }
        return ans;
    }
};
/*
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
User Accepted:1929
User Tried:3391
Total Accepted:2005
Total Submissions:7025
Difficulty:Medium
Given an array nums and an integer target.

Return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 2
Output: 2
Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
Example 2:

Input: nums = [-1,3,5,1,4,2,-9], target = 6
Output: 2
Explanation: There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.



*/