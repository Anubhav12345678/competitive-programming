#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200001],b[200005],i,j,k,l,w;
//https://ideone.com/Tsm5Y0
void dfs(ll v)
{
	b[j]=1; //j=index for which it is called
	w++;
	if(b[v]==0)
	{
		b[v]=1;
		dfs(a[v]);
	}
	b[v]=w;
}
int main() {
	ll q,n;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		memset(b,0,sizeof(b));
		for(j=1;j<=n;j++)
		{
			if(b[j]==0){w=0,dfs(a[j]);}
		}
		for(i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<endl;
		memset(b,0,sizeof(b));
		
	}
	// your code goes here
	return 0;
}