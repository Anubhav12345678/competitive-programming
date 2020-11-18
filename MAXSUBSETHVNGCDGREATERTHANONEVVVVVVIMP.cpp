#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    ll i,j,k,l,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        ll res=0;
        sort(v.begin(),v.end(),greater<>());
        // for(i=0;i<n;i++)
        //     cout<<v[i]<<" ";
        l=0;
        ll ans=0;
        ll h = *max_element(v.begin(),v.end());
        for(k=2;k<=h;k++)
        {
            l=0;
            for(i=0;i<n;i++)
                if(v[i]%k==0)
                    l++;
            ans = max(ans,l);
            
        }
        cout<<ans<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
