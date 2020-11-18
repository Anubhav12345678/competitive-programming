#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll precount[32][200005];
void fill(vector<ll> &a,ll k)
{
    ll n = a.size();
    ll i,j,l,res=0;
     ll ans=0;
    for(i=0;i<32;i++)
    {
        precount[i][0] = ((a[0]>>i)&1);
        for(j=1;j<n;j++)
        {
            precount[i][j] = ((a[j]>>i)&1);
            precount[i][j]+=precount[i][j-1];
        }
    }
    
    
}
ll rangeor(ll l,ll r)
{
    ll x,i,j,k,ans=0;
    for(i=0;i<32;i++)
    {
        if(l==0)
            x = precount[i][r];
        else
            x = precount[i][r]-precount[i][l-1];
        if(x!=0)
            ans = ans|(1<<i);
    }
    return ans;
}
ll solve(vector<ll> &a,ll k)
{
    
    ll n = a.size();
    fill(a,k);
    ll i,j,l,ans=0,r;
    // if(k==0)
    ll K = n-k;
    if(k==0)
    {
        for(i=0;i<n;i++)
            ans = ans|a[i];
        return ans;
    }
    ans=0;
    for(i=K;i<n;i++)
    {
        l = max(i-K,0LL);
        r = min(i-1,n-1);
        ans = max(ans,rangeor(l,r));
    }
    return ans;
}

int main() {
    ll t,i,j,k,l,n;
    cin>>t;
    
    while(t--)
    {
        memset(precount,0,sizeof(precount));
        cin>>n>>k;
        vector<ll> a(n);
        for(i=0;i<n;i++) cin>>a[i];
        cout<<solve(a,k)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
