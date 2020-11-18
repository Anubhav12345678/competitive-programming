
/*

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X. 
 Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other;
 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.




*/




class Solution {
public:
    int rotatedDigits(int N) {
        int res=0;
        int i,j,k,l;
        for(i=1;i<=N;i++)
        {
            bool contain347=0;
            bool contain2569=0;
            j=i;
            while(j)
            {
                k=j%10;
                if(k==2||k==5||k==6||k==9)
                    contain2569=1;
                if(k==3||k==4||k==7)
                    contain347=1;
                j=j/10;
            }
            if(!contain347&&contain2569)
                res++;
        }
        return res;
    }
};