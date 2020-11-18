#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n,ll x,ll k,ll l)
{
   ll cost=0,inc=0,dec=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]<x)
            inc+=(x-a[i]);
        else if(a[i]>x)
            dec+=(a[i]-x);
    }
    cost = (dec)*k+(inc-dec)*l;
    if(dec<=inc)
        return cost;
    return INT_MAX;
}
int main() {
      ll n,k,l,i,j,b,c=0,s=0;
    cin>>n>>k>>l;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i],s+=a[i];
    if(s%n==0)
        s=s/n;
    else
        s=(s/n)+1;
    sort(a,a+n);
    ll mini = a[0];
    ll maxi = a[n-1];
    ll ans = INT_MAX;
    for(ll x=mini;x<=maxi;x++)
    {
        ll p = solve(a,n,x,k,l);
        // cout<<"x = "<<x<<" p = "<<p<<endl;
        ans = min(p,ans);
    }
    
    cout<<ans<<endl;
    
	// Write your code here
}