class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int  i,j,k,l,n;
        if(N<10) return N;
        string s = to_string(N);
        n = s.size();
        if(n<=1)
            return N;
        int marker=INT_MAX;
        for(i=n-1;i>0;i--){
            if(s[i]<s[i-1])
            {
                marker = i;
                s[i-1] = s[i-1]-1;
            }
        }
        for(i=marker;i<n;i++) s[i] = '9';
        return stoi(s);
    }
};
/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9


*/