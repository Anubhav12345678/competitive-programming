

/*

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive
 numbers
Return True if its possible otherwise return False.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].



*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0||k==0)
            return 0;
        sort(nums.begin(),nums.end());
        if(k==n)
            return (nums[n-1]-nums[0])==n-1;
        int i,j,l,p;
        map<int,int> m;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(m[nums[i]]>0)
            {
                for(j=0;j<k;j++)
                {
                    if(m.find(nums[i]+j)==m.end())
                        return 0;
                    if(m[nums[i]+j]<=0)
                        return 0;
                    m[nums[i]+j]--;
                }
            }
        }
        return 1;
            
    }
};