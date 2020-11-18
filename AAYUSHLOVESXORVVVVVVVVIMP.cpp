
/*
Aayush has been given an array a consisting of n  integers A =a1,a2,a3.......an . He has to answer q questions asked by his teacher. In each 
question, the teacher gives Aayush an integer x. Aayush has to find the sum of the transformed array B = (a1)xor(x),(a2)xor(x),(a3)xor(x),(a4)xor(x)....(an)xor(x). After Aayush is done
 answering the question he has to discard array  and use array  for the subsequent queries.



*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll power[22];
void fill()
{
    ll i,j,k,l;
    for(i=0;i<22;i++)
        power[i]=0LL;
    power[0]=1LL;
    for(i=1;i<=21;i++)
        power[i]=power[i-1]*(2*1LL);
}
int main() {
    fill();
    ll i,j,k,l,n;
    scanf("%lld",&n);
    vector<ll> v(n);
    
    ll c[32]={0};
    for(i=0;i<n;i++)
    {
        scanf("%lld",&v[i]);
        ll t = v[i];
        ll j=0;
        while(t)
        {
            if(t%2)
            {
                c[j]++;
            }
            j++;
            t/=2;
        }
    }
    // for(i=0;i<32;i++)
    //     cout<<"c["<<i<<" ] = "<<c[i]<<endl;
    // cout<<endl;
    ll q,x;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&x);
        ll j=0,ans=0;
        while(j<=21)
        {
            ll t = x%2;
            if(t&1)
            {
                ans = ans+power[j]*(n-c[j]);
                c[j] = n-c[j];
            }
            else{
                ans = ans+power[j]*c[j];
            }
            j++;
            x/=2;
        }
        printf("%lld\n",ans);
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
