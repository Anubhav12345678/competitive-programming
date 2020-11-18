# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int n,k,ct;
bool vis[100005];
/*
Matt loves Graph Theory. He recently enrolled into the Algorithms course and started liking it too. His teacher understood his 
love for graphs and decided to give him a problem.

She gives him a Tree and asks him to write a program to find if it's connected or not. She realizes that Matt would do this in no
 time. So, instead she gives him a Graph and then removes a vertex from it and now asks him to find if the resultant graph is 
 connected or not.

Since he is new to programming and algorithms, you have to help him solve this problem.
*/
void dfs(int i,std::vector<int> g[]){
vis[i]=1;
for(auto x : g[i])
{
if(!vis[x])
dfs(x,g);
}
}

int main(){
cin>>n>>k;
std::vector<int> g[n+1];
memset(vis,0,sizeof(vis));
for(int i = 0;i<k;i++)
{
int x,y;
cin>>x>>y;
g[x].pb(y);
g[y].pb(x);
}
int x;
cin>>x;
vis[x] = 1;
for (int i = 0; i < n; ++i)
{
if(!vis[i]){
ct++;
dfs(i,g);
}
}
if(ct>1)cout<< "Not Connected";
else cout<<"Connected" ;
return 0;
}