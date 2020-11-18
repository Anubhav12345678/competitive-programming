#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#include<map>
ll solve(vector<ll> &v,ll x)
{
    ll ans=-1,i,j,k,l,n=v.size();
    map<ll,ll> mp;
    mp[0]=-1;
    ll z=0;
    for(i=0;i<n;i++)
    {
        z = z^v[i];
        if(z==x)
            ans= max(ans,i+1);
        if(mp.find(z^x)!=mp.end())
            ans = max(ans,i-mp[z^x]);
        if(mp.find(z)==mp.end())
        mp[z] = i;
    }
    return ans;
}

int main() {
    ll i,j,k,l,n,x,t;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    cin>>x;
    cout<<solve(v,x)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
