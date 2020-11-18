#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[8][2] = {{0 , 1}, {0 , -1}, {1 , 0}, {-1 , 0}, {1 , 1}, {1 , -1}, {-1 , -1}, {-1 , 1}};
bool vis1[110][110],vis2[110][110];
bool dfs(ll cmp,ll x,ll y,bool vis[][110],ll n,ll a[][110])
{
	if(cmp==1&&x==n-1)return true;
	if(cmp==2&&y==n-1)return true;
	bool ans=false;
	vis[x][y]=true;
	for(ll i=0;i<8;i++)
	{
		ll m = x+dx[i][0];
		ll p =  y+dx[i][1];
		if(m<0||p<0||m>=n||p>=n)
		continue;
		if(a[m][p]==cmp&&!vis[m][p])
		ans|=dfs(cmp,m,p,vis,n,a);
	}
	return ans;
}
int main() {
	ll n;
	cin>>n;
	ll a[110][110],i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	memset(vis1,false,sizeof(vis1));
	memset(vis1,false,sizeof(vis2));
	bool ones=false,twos=false;
	for(ll i = 0; i < n  && !ones ; i++){
 
        if(a[0][i] == 1 && !vis1[0][i]) ones = dfs(1,0 , i , vis1,n,a);      // check for a path from the first row
    }
 
    for(ll i = 0; i < n  && !twos ; i++){
 
        if(a[i][0] == 2 && !vis2[i][0]) twos = dfs(2,i , 0 , vis2,n,a);      // check for a path from the second row
    }
    if(ones&&twos)
    cout<<"AMBIGUOUS\n";
    else if(ones)
    cout<<1<<endl;
    else if(twos)
    cout<<2<<endl;
    else
    cout<<0<<endl;
    
	// your code goes here
	return 0;
}