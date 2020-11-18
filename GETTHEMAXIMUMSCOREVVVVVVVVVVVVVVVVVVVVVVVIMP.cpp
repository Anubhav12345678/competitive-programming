class Solution {
public:
    vector<int> a,b;
    vector<long> fw,bw;
    int binsearch(vector<int> &v,int l,int r,int x){
        if(l>r) return -1;
        if(l==r&&v[l]==x) return l;
        int m = (l+r)>>1;
        if(v[m]==x) return m;
        if(v[m]<x)
            return binsearch(v,m+1,r,x);
        return binsearch(v,l,m-1,x);
    }
    long solve2(int i){
        if(i>=b.size()) return 0;
        if(bw[i]!=-1) return bw[i];
        long s1 = b[i]+solve2(i+1);
        int idx = binsearch(a,0,a.size()-1,b[i]);
        if(idx>=0) s1 = max(s1,b[i]+solve1(idx+1));
        return bw[i]= s1;
    }
    long solve1(int i){
        if(i>=a.size()) return 0;
        if(fw[i]!=-1) return fw[i];
        long s1 = a[i]+solve1(i+1);
        int idx = binsearch(b,0,b.size()-1,a[i]);
        if(idx>=0) s1 = max(s1,a[i]+solve2(idx+1));
        return fw[i]= s1;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
       a=nums1,b=nums2;
        fw.resize(nums1.size(),-1);
        bw.resize(nums2.size(),-1);
        return max(solve1(0),solve2(0))%1000000007;
    }
};
/*
You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed
 to change your path to the other array. (Only one repeated value is considered in the valid path).
Score is defined as the sum of uniques values in a valid path.

Return the maximum score you can obtain of all possible valid paths.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:



Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].


*/