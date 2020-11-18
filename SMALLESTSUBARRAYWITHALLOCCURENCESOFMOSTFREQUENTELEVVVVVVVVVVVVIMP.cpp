#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
ll solve(ll a[],ll n){
    ll i,j,k,l,m;
    map<ll,ll> mp,left;
    ll mx=0,ans=n;
    for(i=0;i<n;i++){
        if(mp.count(a[i])==0){
            mp[a[i]]=1;
            left[a[i]]=i;
        }
        else
            mp[a[i]]++;
        if(mp[a[i]]>mx){
            mx = mp[a[i]];
            ans = i-left[a[i]]+1;
        }
        else if(mp[a[i]]==mx&&(i-left[a[i]]+1)<ans)
            ans = min(i-left[a[i]]+1,ans);
    }
    // for(i=0;i<n;i++)
    //     cout<<"a["<<i<<"] = "<<a[i]<<" left[a[i]] = "<<left[a[i]]<<endl;
    // cout<<mx<<endl;
    return ans;
}
int main() {
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
