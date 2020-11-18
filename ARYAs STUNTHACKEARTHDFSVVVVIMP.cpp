#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n) for(int i=0;i<(n);i++)
const int N=10002;

vector<int> adj[N]; // Adjacency list
vector<bool> vis(N); // Visited vector
vector<int> sold(N); // Storing the no of soldiers in each tent
/*
Arya Stark is now a trained assassin, and her aim is to destroy and kill Queen Cersei to avenge her father’s death. Being a trained assassin, Arya can easily sneak into enemy’s territory.

She uses this ability to enter the area where Cersei’s army is residing into their tents. There are ‘N’ number of tents in this area having ID 1,2,3..N . Some tents may be connected to each other via ropes. Arya wants to kill and injure as many warriors of Cersei’s army by burning the tents.

If there are ‘c’ no. of tents which are connected to each other via ropes, then Arya can light any one of these connected tents as warriors/soldiers of other ‘c-1’ tents will be alarmed by this activity. Suppose, Arya lights tent ‘X’ out of these c tents, then all the warriors of the tent ‘X’ will get killed and the warriors which are in the rest of the connected tents i.e. c-1 tents will get injured.

See sample explanation for more details.
*/
int dfs(int s,int maxid) // Returns the id of the tent which has to be burned in one connnected component
{
vis[s]=1;
for(auto x:adj[s])
{
if(vis[x])
continue;
vis[x]=1;
maxid=dfs(x,maxid);
}
if(sold[s]>sold[maxid])
maxid=s;
else if(sold[s]==sold[maxid] && (s<maxid))
maxid=s;
return maxid;
}
int main()
{
FIO;
int n,m;
cin>>n>>m;
re(i,n)
cin>>sold[i+1];

re(i,m) // Entering the edges in adjcacency list
{
int a,b;
cin>>a>>b;
adj[a].pb(b);
adj[b].pb(a);
}
int ans;
set<int> tentid; // To store the ids of all the tent that have been lit on fire
lli killed=0;
lli injured=0;
for(int i=1;i<=n;i++) // Doing dfs for multiple connected components
{
if(vis[i])
continue;
int ans = dfs(i,i);
tentid.insert(ans);
}
for(int i=1;i<=n;i++)
{
if(tentid.find(i)==tentid.end())
{
injured+=sold[i]; // All the tents that have not been lit have injured soldiers
}
else killed+=sold[i];
}
cout<<killed<<" "<<injured<<endl;
for(auto x: tentid)
{
cout<<x<<" ";
}
}