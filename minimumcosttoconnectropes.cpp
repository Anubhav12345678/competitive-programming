#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#include<vector>
ll solve(ll a[],ll n)
{
    if(n==1)
    return a[0];
    ll i,j,k,sum=0;
    pq<ll, vector<ll>, greater<ll>> q;
    for(i=0;i<n;i++)
    q.push(a[i]);
    while(q.size()!=1)
    {
        ll x = q.top();
        q.pop();
        ll y = q.top();
        q.pop();
        ll z = x+y;
        sum+=z;
        q.push(z);
    }
    return sum;
}
int main() {
    ll t,n,i,a[1000001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        cout<<solve(a,n)<<endl;
    }
	//code
	return 0;
}