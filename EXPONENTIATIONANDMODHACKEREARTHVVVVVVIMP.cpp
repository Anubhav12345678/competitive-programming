#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll power(ll a,ll ind)
{
    if(ind==0LL)
    return 1LL;
    ll x = power(a,ind/2)%mod;
    ll y = (x*x)%mod;
    if(ind%2==0)
    return y%mod;
    else
    return (y*a)%mod;
}
int main()
{
    ll i,j,k,l,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(power(3,n)-power(2,n)+mod)%mod<<endl;
    }
}