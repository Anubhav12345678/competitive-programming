class Solution {
public:
    /*
Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.

    */
    int movesToMakeZigzag(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        int res[2] = {0,0};
        for(i=0;i<n;i++){
            int left = i>0?nums[i-1]:1001;
            int right = i+1<n?nums[i+1]:1001;
            res[i%2]+=max(0,nums[i]-min(left,right)+1); // make this smaller than elements on both the sides
        }
        // res[0] = odd ind valo ko even ind valo se bda krna hai
        // res[1] = even ind valo ko bda krna hai odd ind valo se
        return min(res[0],res[1]);
    }
};
/*
Explanation
Two options, either make A[even] smaller or make A[odd] smaller.
Loop on the whole array A,
find the min(A[i - 1],A[i + 1]),
calculate that the moves need to make smaller than both side.
If it's negative, it means it's already smaller than both side, no moved needed.
Add the moves need to res[i%i].
In the end return the smaller option.


Complexity
Time O(N) for one pass
Space O(2) for two options


*/