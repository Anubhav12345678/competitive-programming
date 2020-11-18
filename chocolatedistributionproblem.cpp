#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
ll solve(ll  a[],ll m,ll n)
{
    sort(a,a+n);
    ll  ans = INT_MAX,i,j,k;
    for(i = 0;i<n-m+1;i++)
    {
        k = i+m-1;
        if(a[k]-a[i]<ans)
        ans = a[k]-a[i];
        if(ans==0)
        break;
    }
    return ans;
}
int main() {
    ll i,j,n,t,a[1000005],m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        cin>>m;
        cout<<solve(a,m,n)<<endl;
    }
	//code
	return 0;
}