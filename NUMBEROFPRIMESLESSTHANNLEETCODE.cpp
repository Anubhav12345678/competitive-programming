class Solution {
public:
    int countPrimes(int n) {
        if(n==0)
            return 0;
       bool isprime[2000005];
       memset(isprime,true,sizeof(isprime));
       isprime[0]=false;
       isprime[1]=false;
        int i,j,k,l;
       for(i=2;i*i<2000005;i++)
       {
           for(j=i*i;j<=2000004;j+=i)
               isprime[j]=false;
       }
    int v[2000005]={0};
    v[0]=v[1]=0;
    for(i=2;i<2000005;i++)
    {
        if(isprime[i])
            v[i] = v[i-1]+1;
        else
            v[i]=v[i-1];
    }
        return v[n-1];
    }
};