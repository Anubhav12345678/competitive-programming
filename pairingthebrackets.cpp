#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#include<vector>
#define pii vector<pair<ll, ll>>
#define pb push_back
int main() {
    ll t;
    string s;
    cin>>t;
    while(t--)
    {
        ll i,j,k;
        cin>>s;
        ll n = s.size();
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        queue<pair<char, ll>> q;
        pii v;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            q.push(make_pair(s[i],i));
            else if(i!=0&&!q.empty())
            {
                pair<char, ll> p = q.front();
                v.pb(make_pair(p.second,i));
                q.pop();
            }
        }
        ll x = v.size();
        cout<<x<<endl;
        if(x>0)
        for(i=0;i<x;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
        
    }
    // your code goes here
    return 0;
}