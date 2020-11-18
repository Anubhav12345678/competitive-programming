class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i,j,k,l,n=nums.size();
        int cnt=0,ans=1;
        int pre=0;
        multiset<int> st;
        for(i=0;i<n;i++)
        {
            st.insert(nums[i]);
            while((*st.rbegin()-*st.begin())>limit)
                st.erase(st.find(nums[pre++]));
            ans = max(ans,i-pre+1);
        }
        return ans;
    }
};
/*

Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

*/