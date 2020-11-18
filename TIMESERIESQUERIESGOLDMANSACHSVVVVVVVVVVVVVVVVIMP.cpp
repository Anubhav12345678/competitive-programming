#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define ff first
#define se second
#define pb push_back
vector<ll>  time1,price1;
vector<ll>  time2,price2;
vector<ll> suf;
void solve(vector<pair<ll,ll>> d){
    sort(d.begin(),d.end());
    time1.pb(d[0].ff);
    price1.pb(d[0].se);
    ll i,j,k,l,n=d.size();
    for(i=1;i<n;i++){
        if(price1.back()<d[i].se){
            price1.pb(d[i].se);
            time1.pb(d[i].ff);
        }
    }
    
    for(auto &p:d) {
        price2.pb(p.se);
        time2.pb(p.ff);
    }
    
    suf.resize(n);
    suf[n-1] = price2[n-1];
    for(i=n-2;i>=0;i--)
        suf[i] = max(suf[i+1],price2[i]);
}

int main(){
    ll i,j,k,l,n,m,q,a,b;
    cin>>n>>q;
    vector<pair<ll,ll>> d(n);
    for(i=0;i<n;i++) cin>>d[i].ff;
    for(i=0;i<n;i++) cin>>d[i].se;
    solve(d);
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(x==1){
            auto it = lower_bound(price1.begin(),price1.end(),y);
            if(it==price1.end()) cout<<-1<<endl;
            else{
                ll idx = it-price1.begin();
                cout<<time1[idx]<<endl;
            }
        }
        else{
            auto it = lower_bound(time2.begin(),time2.end(),y);
            if(it==time2.end()) cout<<-1<<endl;
            else{
                ll idx = it-time2.begin();
                cout<<suf[idx]<<endl;
            }
        }
    }
}
/*
A time series is a series of data points indexed in time order. They are commonly used in the financial world, 
especially in stock markets.

In this challenge you are working with a time series of stock prices. You are given n historical records (ti,pi) where 
the stock at time ti had a price pi. You have to answer 2 types of  queries  q of the form (type,value):

For type 1, given a value v, when was the first time that the price of the stock was at least v?
For type 2, given a value v, what's the maximum price of the stock at a time greater or equal to v?
If for any of these queries the answer is not defined, i.e. there are no historical records that match the query, the answer is .


*/




