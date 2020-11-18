#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define n1 2000010 
#define mod 998244353
//#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
//fflush(stdout) 
int main()
{ 
    //fast  
ios_base::sync_with_stdio(false); cin.tie(NULL); 
ll t;
cin>>t;
for(int k=0;k<t;k++)
{
	ll n,m;
	cin>>n>>m;
	ll ans=0;  
	int c[m+1]; 
	int b[n+1];
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}  
	int a[n+1][3];
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i][0]=x; a[i][1]=y; a[i][2]=z;
	}  
	for(int i=1;i<=n;i++)
	{
		if(c[a[i][0]]>0)
		{
			c[a[i][0]]--; 
            b[i]=a[i][0];
			a[i][0]=0; 
			ans+=a[i][1]; 
		}
	}   
	int j=1;
	for(int i=1;i<=n;i++)
	{  
		if(a[i][0]!=0) 
		{
        while(c[j]<=0 && j<m)
        {
        	j++;
        }  
        if(c[j]>0)
        {
        	c[j]--; 
        	ans+=a[i][2];
        	b[i]=j;
        } 
        }
	} 
	cout<<ans<<endl; 
    for(int i=1;i<=n;i++)
    {
    	cout<<b[i]<<" ";
    } 
    cout<<endl;
}
return 0;
}