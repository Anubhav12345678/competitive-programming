#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
    ll arr1[n],arr2[n],i,j,k=0;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    arr1[0] = a[0];
    arr2[n-1] = a[n-1];
    // ll i,j;
    for(i=1,j=n-2;i<n,j>=0;i++,j--)
    {
        arr1[i] = max(a[i],arr1[i-1]);
        arr2[j] = max(a[j],arr2[j+1]);
    }
    ll res=0;
    for(i=0;i<n;i++)
    res+=min(arr1[i],arr2[i])-a[i];
    return res;
}
int main() {
    ll t,n,a[100001],i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        cout<<solve(a,n)<<endl;
    }
	//code
	return 0;
}