/*

Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1

*/



class Solution {
public:
    int solve(vector<int> &v,int l,int r)
    {
        if(l>r)
            return -1;
        if(l==r)
            return l;
        int m = (l+r)/2;
        if(m>l&&v[m]>v[m-1]&&m<r&&v[m]>v[m+1])
            return m;
        if(m>l&&v[m]>v[m-1])
            return solve(v,m,r);
        else
            return solve(v,l,m);
    }
    int peakIndexInMountainArray(vector<int>& A) {
        int i,j,k,l,n=A.size();
        return solve(A,0,n-1);
    }
};