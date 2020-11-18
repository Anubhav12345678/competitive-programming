#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

Given  and an array of size . Find the maximum possible subarray sum in the array.

Seems quite easy, isn't it?

But there's a twist. You are allowed to perform squaring of atmost one element in the array. Now find what's the maximum possible subarray sum.


*/
int  main()
{
    ll i,j,k,l,t,n;
    cin>>n;
    ll a[100010],b[100010],c[100010];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i] = b[i-1]+a[i];
        if(b[i]<0)
        b[i]=0;
    }
    for(i=n;i>=1;i--)
    {
        c[i] = c[i+1]+a[i];
        if(c[i]<0)
        c[i]=0;
    }
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        ans = max(ans,b[i-1]+a[i]*a[i]+c[i+1]);
    }
    cout<<ans<<endl;
}