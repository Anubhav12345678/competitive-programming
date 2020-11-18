#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
#include<set>
#define ff first
#define se second
/*

On New Year's Eve, five robbers - Nobita, Shizuka, Dekisugi, Giyan and Sunyo decided to rob a museum in Tokyo.
After passing through all security gates, they arrived to the final room. But there was a problem.

Between the entrance of the room and the precious items, there were small sensors on the floor. Near the gate, 
they found a map describing the layout of the sensors.

Since Dekisugi is the best at geometry, he decided to draw it out on the  plane. 

Each sensor is at a particular coordinate on the  Plane. Also, each sensor is connected 
to every other sensor with a laser beam. A beam is a straight line on the  plane and it 
extends infinitely in both directions. If there are more than two sensors lying on the same
 line, they are connected by a single laser beam. He needs your help, to find out how many pairs of beams are intersecting.



*/
ll solve(ll n,vector<pair<ll,ll>> &v)
{
    ll i,j,k,l,m;
    map<pair<ll,ll>,set<ll>> mp;
    set<pair<ll,ll>> st;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ll dx = v[j].ff-v[i].ff;
            ll dy = v[j].se-v[i].se;
            ll k = __gcd(dx,dy);
            dx/=k;
            dy/=k;
            ll c = dy*v[i].ff-dx*v[i].se;
            st.insert({dx,dy});
            mp[{dx,dy}].insert(c);
        }
    }
    ll ans=0LL,sub=0;
    for(auto it:st)
    {
        ans+=mp[it].size();
        sub+=(mp[it].size()*(mp[it].size()-1))/2;
    }
    return (ans*(ans-1))/2-sub;
    
}
int main() {
    
    ll i,j,k,l,n;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(i=0;i<n;i++)
        cin>>v[i].ff>>v[i].se;
    cout<<solve(n,v)<<endl;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}