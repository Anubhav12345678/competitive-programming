class Solution {
public:
    /*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.



    */
    int longest(vector<int> &v){
        int i,j,k,l,n=v.size();
        vector<int> negpos;
        int x=0;
        for(i=0;i<n;i++){
            if(v[i]<0){
                negpos.push_back(i);
                x++;
            }
        }
        if(x%2==0) return n;
        return max(n-negpos[0]-1,negpos.back());
    }
    int getMaxLen(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        int ans=0;
        for(i=0;i<n;){
            if(nums[i]==0){
                i++;
                continue;
            }
            j=i;
            vector<int> v;
            while(j<n&&nums[j]) v.push_back(nums[j++]);
            ans = max(ans,longest(v));
            i=j;
        }
        return ans;
    }
};