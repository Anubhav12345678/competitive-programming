#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<deque>
#include<vector>
ll solve(vector<ll> &v,ll x)
{
    ll i,j,k,l,n=v.size();
    ll ans=n+1;
    vector<ll> s(n+1,0);
    ll cursum=0;
    ll en=0,st=0;
    while(en<n)
    {
        while(cursum<=x&&en<n)
        cursum+=v[en++];
        while(cursum>x&&st<n)
        {
            if(ans>(en-st))
            ans = en-st;
            cursum-=v[st++];
        }
    }
    return ans;
}
int main() {
    ll i,j,k,l,n,t,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        vector<ll> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        cout<<solve(v,x)<<endl;
    }
	//code
	return 0;
}