

/*

Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if
 for every integer X from 1 to N, the binary representation of X is a substring of S.

 

Example 1:

Input: S = "0110", N = 3
Output: true
Example 2:

Input: S = "0110", N = 4
Output: false


*/



class Solution {
public:
    bool queryString(string S, int N,int x=0) {
        int i,j,k,l,n=S.size();
        int num=0;
        vector<bool > v(N);
        // memset(v,0,sizeof(v));
        // int x=0;
        for(i=0;i<n&&x<N;i++)
        {
            if(S[i]=='0') continue;
            for(j=i,num=0;num<=N&&j<S.size();j++)
            {
                num=(num<<1)+(S[j]-'0');
                if(num>0&&num<=N&&!v[num-1])
                {
                    x++;
                    v[num-1]=1;
                }
            }
        }
        return x==N;
    }
};