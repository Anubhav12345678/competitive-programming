class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i,j,k,l=0,r=n-1;
        while(l<n-1&&arr[l]<=arr[l+1]) l++;
        while(r>0&&arr[r-1]<=arr[r]) r--;
        if(l>=r) return 0;
        j=r;
        // len = max sorted subarray len
        int len = max(l+1,n-r);
        for(i=0;i<=l;i++){
            while(j<n&&arr[j]<arr[i]) j++;
            if(j==n) break;
            len = max(len,i+1+n-j);
        }
        
        return n-len;
    }
};
/*

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

A subarray is a contiguous subsequence of the array.

Return the length of the shortest subarray to remove.

 

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

*/