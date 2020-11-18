
/*
You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 

Example 1:

Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.




*/
class Solution {
public:
    int getnext(int ind,vector<int> &nums)
    {
        return (ind+nums[ind]+nums.size())%nums.size();
    }
    bool circularArrayLoop(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        for(i=0;i<n;i++)
        {
            int sl=i,fs=i;
            while(nums[sl]*nums[getnext(sl,nums)]>0&&
                  nums[fs]*nums[getnext(fs,nums)]>0&&
                  nums[fs]*nums[getnext(getnext(fs,nums),nums)]>0)
            {
                sl = getnext(sl,nums);
                fs = getnext(getnext(fs,nums),nums);
                if(sl==fs)
                {
                    if(sl==getnext(sl,nums)) // len of cycle is one
                        break;
                    return 1;
                }
            }
            sl=i;
            int val = nums[sl];
            while(val*nums[sl]>0)
            {
                int x = sl;
                sl = getnext(sl,nums);
                nums[x]=0;
            }
        }
        return 0;
    }
};