class Solution {
public:
    /*
    Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

    */
    void wiggleSort(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n<=1)
            return;
        sort(nums.begin(),nums.end());
        vector<int> res(n);
        int left=(n-1)/2;
        int right=n-1;
        for(i=0;i<n;i++)
        {
            //nums[0] < nums[1] > nums[2] < nums[3]....
            if(i%2==0)
            {
                res[i]=nums[left--];
            }
            else
                res[i] = nums[right--];
        }
        nums=res;
    }
};