#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
You are given an array, on which you can perform the following operation any number of times:
Take some element  and move it to some index  such that . In general, if we have the following array:

After moving  to index , the new array will be:

You need to tell what is the minimum number of times the operation should be performed in order to sort the array.


*/
ll ceilind(vector<ll> &v,ll l,ll r,ll x)
{
    while(r-l>1)
    {
        ll m = l+(r-l)/2;
        if(v[m]>=x)
            r=m;
        else
            l=m;
    }
    return r;
}

ll solve(vector<ll> &v)
{
    if(v.size()==0) return 0;
    vector<ll> res(v.size());
    ll i,j,k,l,n=v.size(),len=1;
    res[0]=v[0];
        for(i=1;i<n;i++)
        {
            if(v[i]<res[0])
                res[0]=v[i];
            else if(v[i]>res[len-1])
                res[len++]=v[i];
            else
                res[ceilind(res,-1,len-1,v[i])]=v[i];
        }
    
    return len;
}
int main() {
    ll i,j,k,l,n;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    cout<<n-solve(v)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
