
//Given an array A of size N and an integer K, for each prefix of A  of size>=k print its KTH largest element.
// Note: All array elements are distinct.



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    set<ll>s;
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
        if(s.size()>k)
            s.erase(s.begin());
        if(s.size()>=k)
        {
            auto itr=s.begin();
            ll val=*(itr);
            cout<<val<<" ";
        }
    }
    cout<<endl;
    return 0;
}