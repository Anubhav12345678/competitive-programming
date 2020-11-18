
/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"



*/



class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        int tmp=1;
        int i,j,l;
        for(i=0;i<n;i++)
        {
            v.push_back(i+1);
            tmp*=(i+1);
        }
        string res="";
        for(;n>0;n--)
        {
            tmp = tmp/n;
            int pickid = (k-1)/tmp;
            res.push_back(v[pickid]+'0');
            v.erase(v.begin()+pickid);
            k-=pickid*tmp;
        }
        return res;
    }
};