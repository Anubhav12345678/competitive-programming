
/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an 
arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

 

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.
Example 3:

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].



*/



class Solution {
public:
    int longestSubsequence(vector<int>& a, int difference) {
        map<int,int> res;
        int i,j,k,l,n=a.size();
        int ans=1;
        for(i=0;i<n;i++)
        {
            int x = a[i];
            res[x] = res[x-difference]+1;
            ans= max(ans,res[x]);
        }
        return ans;
    }
};