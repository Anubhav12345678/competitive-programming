class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i,j,k,l=0,n=nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        int r=0,res=1e9;
        while(l<=r)
        {
            if(s>=x)
            {
                if(s==x)
                    res=min(res,l+n-r);
                if(r<n)
                    s-=nums[r++];
                else
                    break;
            }
            else
                s+=nums[l++];
        }
        return (res==1e9)?-1:res;
    }
};  

/*

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.



*/