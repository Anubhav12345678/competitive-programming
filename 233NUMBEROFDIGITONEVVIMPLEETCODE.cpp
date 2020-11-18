/*

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.


*/



class Solution {
public:
    int countDigitOne(int n) {
        long long int i,j,k,l,res=0;
        for(i=1;i<=n;i*=10)
        {
            long long int div = i*10;
            res+=(n/div)*i+min(max(n%div-i+1,0LL),i);
        }
        return res;
    }
};