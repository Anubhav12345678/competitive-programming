#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*

What is the immediate thing you try to find whenever there is some kind of trouble in your life ? Well ; you want to
 surround yourself with your friends.

Lets define friendship in a formal way :

a and b are friends of each other ; in case you are told that they are friends ( This is called direct friendship )

Or ; in case ; if you are told that a is a friend of b , b is a friend of c ; then you can say that a and  c are 
friends too. ( This is called in-direct friendship ).

So ; you may note ; that friendship is a transitive relationship.

The are n students in a class of Montfort School ; such that we have m people who are directly friends with one another.

Naturally , there is a possibility ; that a class is distributed into several groups of friends. A group is defined as a 
collection of people ; such that any two people of the same group are direct / in-direct friends with one another.

The strength of a group is defined as the number of direct friendship relations in that group. Given Q queries ; where-in 
each query ; you will be given 'id' of some person ; determine the strength of his group.




*/
#include<vector>
vector<ll> par;
vector<ll> grp[100005];
ll find(ll x){
    if(par[x]==x)
        return x;
    return find(par[x]);
}

// void union()

int main() {
    // par = vector<ll>(100005,-1);
    ll q,i,j,k,l,n,m,a,b;
    cin>>n>>m;
    par =  vector<ll>(n+1);
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
    map<ll,ll> mp;
    for(i=1;i<=n;i++) mp[i]=1;
    while(m--)
    {
        cin>>a>>b;
        ll x = find(a);
        ll y = find(b);
        if(x!=y)
        {
            par[y]=x;
            mp[x]+=mp[y];
            mp[y]=0;
        }
        else{
            mp[x]++;
        }
    }
    // for(i=1;i<=n;i++)
    //     mp[par[i]]++;
    vector<bool> vis(n,false);
    for(i=1;i<=n;i++)
    {
        if(!vis[par[i]])
        {
            mp[par[i]]-=1;
            vis[par[i]]=1;
        }
        // cout<<"par["<<i<<"] = "<<par[i]<<" mp[par["<<i<<"]] = "<<mp[par[i]]<<" "<<endl;
    }
    cin>>q;
    while(q--)
    {
        ll id;
        cin>>id;
        cout<<mp[par[id]]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
