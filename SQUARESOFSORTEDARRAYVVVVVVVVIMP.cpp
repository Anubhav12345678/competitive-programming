class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i,j,k,l,n=A.size();
        i=0;
        j=0;
        k=0;
        vector<int> v(n);
        while(j<n&&A[j]<0)
            j++;
        i=j-1;
        while(i>=0&&j<n)
        {
            if((A[i]*A[i])<(A[j]*A[j]))
            {
                v[k++]=A[i]*A[i];
                i--;
            }
            else
            {
                v[k++]=A[j]*A[j];
                j++;
            }
        }
        while(i>=0)
        {
            v[k++]=A[i]*A[i];
                i--;
        }
        while(j<n)
        {
            v[k++]=A[j]*A[j];
                j++;
        }
        
        return v;
    }
};
/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]



*/