#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define ll long long
#define pb push_back
void solve(vector<vector<ll>> &res,vector<ll> &v,ll st,ll n,vector<ll> &a,ll k)
{
    if(k==0)
    {
        if(find(res.begin(),res.end(),v)==res.end());
        res.push_back(v);
        return;
    }
    if(st>=n)
        return;
    v.pb(a[st]);
    solve(res,v,st+1,n,a,k-1);
    v.pop_back();
    solve(res,v,st+1,n,a,k);
}
int main() {
    ll n,i,j,k,l;
    cin>>n;
    vector<vector<ll>> res;
    vector<ll> v,a(n);
    for(i=0;i<n;i++) cin>>a[i];
    if(n==12)
    {
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
    
    else
    {
        solve(res,v,0,n,a,12);
        for(i=0;i<res.size();i++)
        {
            for(j=0;j<res[i].size();j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
	// Write your code here
}