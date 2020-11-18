#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define ff first
#define se second

int main() {
    ll a,n,i,j,k,l,sum=0;
    cin>>n;
    vector<ll> b(n);
    map<ll,vector<ll>> mp;
    for(i=0;i<n;i++)
        cin>>a>>b[i], mp[b[i]].push_back(a);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        vector<ll> &tmp  = it->se;
        sort(tmp.begin(),tmp.end());
        it->se = tmp;
    }
    ll ans=0;
    for(i=0;i<n;i++)
    {
        ans+=mp[b[i]].back()*(i+1);
        mp[b[i]].pop_back();
    }
    cout<<ans;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
