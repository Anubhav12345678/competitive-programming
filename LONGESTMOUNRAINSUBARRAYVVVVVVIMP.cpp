class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int ans=0,base=0;
        while(base<n)
        {
            int en=base;
            if(en+1<n&&A[en]<A[en+1])
            {
                while(en+1<n&&A[en]<A[en+1]) en++;
                if(en+1<n&&A[en]>A[en+1])
                {
                   while(en+1<n&&A[en]>A[en+1]) en++;
                    ans = max(ans,en-base+1);
                }
            }
            base = max(en,base+1);
        }
        return ans;
    }
};
/*

Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.



*/