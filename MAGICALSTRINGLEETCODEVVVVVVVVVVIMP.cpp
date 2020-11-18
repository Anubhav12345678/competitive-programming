

/*

A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2'
 generates the string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"
//is upar vali string me nth (1-indexing) tk kitne 1 aaye hbs ye btana h

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2 2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.




*/


class Solution {
public:
    int magicalString(int n) {
        if(n<=0)
            return 0;
        if(n<4) return 1;
        int i,j,k,l,num=1,ret=1,head=2;
        int magstr[n+1];
        magstr[0]=1;
        magstr[1]=2;
        magstr[2]=2;
        int tail=3;
        while(tail<n)
        {
            for(i=0;i<magstr[head];i++)
            {
                magstr[tail]=num;
                if(num==1&&tail<n) ret++;
                tail++;
            }
            head++;
            num=3-num;
        }
        return ret;
    }
};