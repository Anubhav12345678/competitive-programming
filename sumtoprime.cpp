#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isprime[1000005];
ll sum[1000005];
void fill()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0] = false;
    isprime[1] = false;
    ll i,j;
    for(i=2;i*i<=1000004;i++)
    {
        for(j=i*i;j<=1000004;j+=i)
        isprime[j] = false;
    }
    memset(sum,0,sizeof(sum));
    sum[0] = 0;
    sum[1] = 0;
    ll u=2;
    ll k = 0;
    for(i=2;i<=1000004;i++)
    {
        
        if(isprime[i])
        {
        sum[i] = sum[i-1]+i;
        k=sum[i];
        }
        else
        sum[i]=k;
        
    }

}
// ll solve(ll n)
// {
//     if(n==1)
//     return 0;
//     ll s=0,i,j;
//     // bool isprime[n+1];
//     // memset(isprime,true,sizeof(isprime));
//     // for(i=2;i*i<=n;i++)
//     // {
//     //     for(j=i*i;j<=n;j+=i)
//     //     isprime[j] = false;
//     // }
//     // for(i=2;i<=n;i++)
//     // if(isprime[i])
//     // s+=i;
//     // return s;
    
// }
int main() {
    ll t,n;
    fill();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<sum[n]<<endl;
    }
	//code
	return 0;
}