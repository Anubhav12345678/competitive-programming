#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define mod 1e9+7
/*
Given  distinct objects of type  ; and  distinct objects of type 2.

Find the number of permutations ; such that no type  object is adjacent to some type  object ;
 and no type  object is adjacent to some type  object.

Since the number of permutations can be large ; print it modulo 

Input Format

First line of the input conists of a single integer  ; denoting the number of test cases.

Then  lines follow ; each containing two space seperated integers  and  ; representing the 
number of type  and type  objects respectively.





*/
ll mod=1e9+7;
ll fac[1000005];
void fill()
{
    fac[0]=1LL;
    for(ll i=1;i<1000005;i++)
    {
        fac[i] = fac[i-1]*i;
        fac[i]%=mod;
    }
}
int main() {
    memset(fac,1LL,sizeof(fac));
    fill();
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(abs(a-b)>1) cout<<0LL<<endl;
        else
        {
            ll ans= (fac[a]*fac[b])%mod;
            ll x=1;
            if(a==b) x=2;
            cout<<(ans*x)%mod<<endl;
        }
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
