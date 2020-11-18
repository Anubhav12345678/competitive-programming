#include<bits/stdc++.h>
using namespace std;
#define INF 999999
int t,n,m,arr[20][20],x,y,dp[20][20];
bool vis[20][20];

int solve(int i,int j,int x,int y)
{
	
	if(arr[i][j]==0 || vis[i][j])return INF;
	if(i==x && j==y)return 0;
	if(dp[i][j]<INF)return dp[i][j];
	
	vis[i][j]=true;
	if(i+1<n && !vis[i+1][j])dp[i][j]=min(dp[i][j],solve(i+1,j,x,y));
	if(i-1>=0 && !vis[i-1][j])dp[i][j]=min(dp[i][j],solve(i-1,j,x,y));
	if(j+1<m && !vis[i][j+1])dp[i][j]=min(dp[i][j],solve(i,j+1,x,y));
	if(j-1>=0 && !vis[i][j-1])dp[i][j]=min(dp[i][j],solve(i,j-1,x,y));
	
	
    dp[i][j]+=1;
	return dp[i][j];
}

bool possible(int i,int j,int x,int y)
{

    if(arr[i][j]==0)
    return false;
    
    if(i==x && j==y)return true;
    
    vis[i][j]=true;
    
    if(i+1<n && !vis[i+1][j])
    {
     if(possible(i+1,j,x,y))
       return true;
    }
    if(i-1>=0 && !vis[i-1][j])
    {
        if(possible(i-1,j,x,y))
          return true;
    }
    if(j+1<m && !vis[i][j+1])
    {
        if(possible(i,j+1,x,y))
         return true;
    }
    if(j-1>=0 && !vis[i][j-1])
    {
        if(possible(i,j-1,x,y))
          return true;
    }
    return false;
    
}

int main()
{

cin>>t;
while(t--)
{
cin>>n>>m;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
        
    }
}
memset(vis,false,sizeof(vis));
cin>>x>>y;

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        dp[i][j]=INF;
    }
}


if(possible(0,0,x,y))
{
	
	memset(vis,false,sizeof(vis));
    cout<<solve(0,0,x,y)<<endl;
}
else 
{
    cout<<-1<<endl;
}

}


}