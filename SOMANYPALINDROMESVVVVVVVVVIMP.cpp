#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
//Given an integer n, you have to print sum of all n digit palindromic numbers which are divisible by 9 and contain no 
// 0 in their decimal representation modulus .
ll power(ll n,ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p%2==1)
        {
            ans = (ans*n)%mod;
        }
        p=p/2;
        n=(n*n)%mod;
    }
    return ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<9<<"\n";
        return 0;
    }
    else if(n==2)
    {
        cout<<99<<"\n";
        return 0;
    }
    else
    {
        ll ans = 0;
        if(n%2==1)
        {
            ll nine = 9;
            ll two =10;
            ans = (45*power(nine,n/2-1))%mod;
            // cout<<"ans = "<<ans<<endl;
            ll temp=0;
            for(ll i=0;i<=(n-1);i++)
            {
                temp = (temp%mod + power(two,i)%mod)%mod;
            }
            // cout<<temp<<endl;
            cout<<(ans*temp)%mod<<"\n";
        }
        else
        {
            ll nine = 9;
            ll two =10;
            ans = (45*power(nine,n/2-2))%mod;
            // cout<<"ans = "<<ans<<endl;
            ll temp=0;
            for(ll i=0;i<=(n-1);i++)
            {
                temp = (temp%mod + power(two,i)%mod)%mod;
            }
            // cout<<temp<<endl;
            cout<<(ans*temp)%mod<<"\n";
        }
    }
    return 0;
}