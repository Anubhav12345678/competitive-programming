#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#include<deque>
#include<queue>
int main() {
    ll i,j,k,l,n;
    cin>>n>>k;
    vector<ll> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    deque<ll> d1(k),d2(k);
    for(i=0;i<k;i++)
    {
        while(!d1.empty()&&v[i]>=v[d1.back()])
            d1.pop_back();
        while(!d2.empty()&&v[i]<=v[d2.back()])
            d2.pop_back();
        d1.push_back(i);
        d2.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<v[d1.front()]+v[d2.front()]<<" ";
        while(!d1.empty()&&d1.front()<=i-k)
            d1.pop_front();
        while(!d2.empty()&&d2.front()<=i-k)
            d2.pop_front();
        while(!d1.empty()&&v[i]>=v[d1.back()])
            d1.pop_back();
        while(!d2.empty()&&v[i]<=v[d2.back()])
            d2.pop_back();
        d1.push_back(i);
        d2.push_back(i);
    }
    // print result for last window
    cout<<v[d1.front()]+v[d2.front()]<<" ";
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
