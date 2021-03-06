

/*

Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers 
successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
 

Now given N, how many beautiful arrangements can you construct?

Example 1:

Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.




*/


class Solution {
public:
    int cnt=0;
    void solve(int n,int pos,bool use[])
    {
        if(pos>n)
        {
            cnt++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(use[i]==0&&(i%pos==0||pos%i==0))
            {
                use[i]=1;
                solve(n,pos+1,use);
                use[i]=0;
            }
        }
    }
    int countArrangement(int N) {
        if(N==0)
            return 0;
        bool use[N+1];
        memset(use,0,sizeof(use));
        solve(N,1,use);
        return cnt;
    }
    
};