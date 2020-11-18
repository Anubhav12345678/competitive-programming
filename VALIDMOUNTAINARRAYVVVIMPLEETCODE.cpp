class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i,j,k,l,n=A.size();
        if(n<3)
            return 0;
        i=0;
        while(i<n-1&&A[i]<A[i+1])
            i++;
        if(i==n-1||i==0)
            return 0;
        while(i<n-1&&A[i]>A[i+1])
            i++;
        return i==n-1;
    }
};
/*

Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]


*/