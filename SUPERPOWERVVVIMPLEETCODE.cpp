
/*

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given 
in the form of an array.

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024



*/




class Solution {
public:
    int mod=1337;
    long long int modpow(int a,int b)
    {
        if(b==0)
            return 1LL;
        long long int x = modpow(a,b/2)%mod;
        if(b%2==0)
            return ((x%mod)*(x%mod))%mod;
        else
            return ((a%mod)*((x%mod)*(x%mod))%mod)%mod;
    }
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int i,j,k,l;
        long long int res=0;
        res = modpow(a,b[0])%mod;
        for(i=1;i<n;i++)
            res = ((modpow(res,10)%mod)*modpow(a,b[i])%mod)%mod;
        return res;
        
    
    }
};