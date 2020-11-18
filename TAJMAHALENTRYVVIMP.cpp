#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define ll long long
#include<limits.h>
ll binsearch(ll i,ll n,ll num)
{
    ll s=0,e = INT_MAX;
    ll ans;
    while(s<=e)
    {
        ll m = s+(e-s)/2;
        if((i+m*n)>=num)
        {
            ans  = m;
            e = m-1;
        }
        else
            s=m+1;
        
    }
    return ans;
}
int main()
{
    ll n,i,j,k,l,ans;
    cin>>n;
    ans = INT_MAX;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    ll res = INT_MAX;
    // ll ans;
    for(i=0;i<n;i++)
    {
        ll p = binsearch(i,n,a[i]);
        if(p<res)
        {
            res=p;
            ans = i+1;
        }
    }
    cout<<ans<<endl;
    
    
    
	return 0;
}
