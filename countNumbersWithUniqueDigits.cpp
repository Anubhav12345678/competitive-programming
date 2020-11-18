class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int res=10;
        int cnt=9;
        int i,j,k,l;
        for(i=2;i<=n;i++)
        {
            cnt*=(10-i+1);// tha pattern
            /*
            
            The trick of this problem is to find the pattern of how to find numbers with unique numbers. The code looks 
            rather easy, but very confusing.

i = 1, 10: nothing is dupliated
i = 2, 9 * 9: the first digit has 9 options (exclude 0), the second digit also has 9 options (exclude the number already taken
 by the first digit, but include 0).
i = 3, 9 * 9 * 8: first two digits follows rules in i = 2, then the third digit has options that exclude all numbers taken by the
 previous two digits.
.
.
.
i     , 9 * 9 * 8 *... * (10 - i + 1),  the last digit has options that exclude those already chosen by all previous digits.

The final result is the sum of all results.
            
            */
            res+=cnt;
        }
        return res;
    }
};