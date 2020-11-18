class Solution {
public:
    int solve(vector<int> &v)
    {
        int i,j,k,l,n=v.size();
        int x = *max_element(v.begin(),v.end());
        int y = *min_element(v.begin(),v.end());
        return abs(x-y);
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int i,j,k,l,n=arr1.size();
        vector<int> s1(n), s2(n), d1(n), d2(n);
        for(i=0;i<n;i++)
        {
            s1[i] = arr1[i]+arr2[i]+i;
            s2[i] = arr1[i]+arr2[i]-i;
            d1[i] = arr1[i]-arr2[i]+i;
            d2[i]  = arr1[i]-arr2[i]-i;
        }
        return max(max(solve(s1),solve(s2)),max(solve(d1),solve(d2)));
    }
};
/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20



*/