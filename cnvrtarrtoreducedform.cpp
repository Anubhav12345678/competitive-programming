#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#define mp make_pair
#define f first
#define s second
#define pq priority_queue
void solve(ll a[],ll n)
{
    pq<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll, ll>>> q;
    ll i=0;
     pair<ll, ll> m;
    // while(!q.empty())
    // {
    //     m = q.top();
    //     a[i++] = 
    // }
    for(i=0;i<n;i++)
    q.push(mp(a[i],i));
    i=0;
    while(!q.empty())
    {
        m = q.top();
        a[m.s] = i++;
        q.pop();
    }
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    
}
int main() {
    ll t,n,a[100001],i;
    cin>>t;
    while(t--)
    {
        cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    solve(a,n);
    cout<<endl;
    }
	//code
	return 0;
}