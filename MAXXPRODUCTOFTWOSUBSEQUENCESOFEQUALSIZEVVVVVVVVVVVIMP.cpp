
/*

5419. Max Dot Product of Two Subsequences
User Accepted:107
User Tried:171
Total Accepted:109
Total Submissions:217
Difficulty:Hard
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some
 (can be none) of the characters without disturbing the relative positions of the remaining characters.
  (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int i,j,k,l,n=nums1.size();
        int m = nums2.size();
        int f[n][m];
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                f[i][j] = nums1[i]*nums2[j];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i>0) f[i][j] = max(f[i][j],f[i-1][j]);
                if(j>0) f[i][j] = max(f[i][j],f[i][j-1]);
                if(i>0&&j>0) f[i][j] = max(f[i][j],f[i-1][j-1]+max(0,nums1[i]*nums2[j]));
            }
        }
        return f[n-1][m-1];
        
        
    }
};