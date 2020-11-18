#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
int main() {
    ll i,j,k,l,n;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    ll cnt=0,tot=0,cnt1=0;
    for(i=0;i<n;i++)
    {
        if(v[i]>0) tot+=(v[i]-1);
        else if(v[i]<0) tot+=(-1-v[i]),cnt1++;
        else 
        {
            tot++;
            cnt++;
        }
        // cout<<tot<<endl;
        // if(cnt1%2&&cnt==0)tot+=2;
        // cout<<tot<<endl;
    }
    if(cnt1%2&&cnt==0)tot+=2;
    cout<<tot<<endl;
    // your code goes here
    return 0;
}