class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int i,j,k,l,n=nums.size();
        k=0;
        for(i=0;i<n;i++){
            k = (k+nums[i])%p;
        }
        
        if(k==0) return k;
        int other=0;
        map<int,int> mp;
        int ans=n;
        mp[0]=-1;
        for(i=0;i<n;i++){
            other = (other+nums[i])%p;
            int tmp = (other-k)%p;
            if(tmp<0) tmp+=p;
            if(mp.find(tmp)!=mp.end())
                ans = min(ans,i-mp[tmp]);
            
            mp[other]=i;
        }
        
        return ans==n?-1:ans;
    }
};
/*
1590. Make Sum Divisible by P
User Accepted:550
User Tried:1838
Total Accepted:566
Total Submissions:4929
Difficulty:Medium
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of 
the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of 


*/