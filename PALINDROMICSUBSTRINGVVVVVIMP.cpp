
/*

You are given a string . You have to find the number of sub-strings of  which can be shuffled to form a palindromic string.

*/

#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ;
ll cnt[100005][26];
ll power[27];
void fill()
{
    power[0]=1LL;
    for(ll i=1;i<=(26*1LL);i++)
        power[i] =  power[i-1]*2;
}
ll solve(string s)
{
    fill();
    ll i,j,k,l,n=s.size();
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<100005;i++)
        for(j=0;j<26;j++)
            cnt[i][j]=0LL;
    cnt[0][s[0]-'a']++;
    for(i=1;i<n;i++)
    {
       cnt[i][s[i]-'a']++;
        for(j=0;j<26;j++)
            cnt[i][j]  = (cnt[i][j]+cnt[i-1][j])%2;
    }
    ll ans=0LL;
    map<ll,ll> mp;
    mp[0]=1LL;
    for(i=0;i<n;i++)
    {
        ll mul=1LL;
        ll curans=0LL;
        ll cur=0LL;
        for(j=0;j<26;j++)
        {
            if(cnt[i][j]==1)
                cur+=mul;
            mul*=2;
        }
        for(j=0;j<26;j++)
            curans+=mp[(cur^power[j])];// VVV imp step h ye
        curans+=mp[cur];
        mp[cur]++;
        ans+=curans;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,k,l,n;
    string s;
    cin>>s;
    n = s.size();
    ll ans=solve(s);
    cout<<ans<<endl;
    
}