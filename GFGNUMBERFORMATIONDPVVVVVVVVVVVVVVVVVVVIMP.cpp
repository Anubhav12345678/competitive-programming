#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll mod = 1e9+7;
/*
Given three integers x,y and z you need to find the sum of all the numbers formed by 
having 4 atmost x times , having 5 atmost y times and having 6 atmost z times as a digit.

Note : Output the sum modulo 10^9+7.



*/
// 4 x times
// 5 y times
// 6 z times
ll solve(ll x,ll y,ll z)
{
	ll i,j,k,l,n;
	ll num[x+1][y+1][z+1], sum[x+1][y+1][z+1];
	memset(num,0,sizeof(num));
	memset(sum,0,sizeof(sum));
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			for(k=0;k<=z;k++)
			{
				if(i==0&&j==0&&k!=0)
				num[i][j][k]=1;
				if(i==0&&j!=0&&k==0)
				num[i][j][k]=1;
				if(i!=0&&j==0&&k==0)
				num[i][j][k]=1;
				// cout<<"num["<<i<<"]["<<j<<"]["<<k<<"] = "<<num[i][j][k]<<endl;
			}
		}
	}
	
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			for(k=0;k<=z;k++)
			{
				if(i>0)
				num[i][j][k]+=num[i-1][j][k];
				if(j>0)
				num[i][j][k]+=num[i][j-1][k];
				if(k>0)
				num[i][j][k]+=num[i][j][k-1];
				// cout<<"num["<<i<<"]["<<j<<"]["<<k<<"] = "<<num[i][j][k]<<endl;
			}
		}
	}
	
for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			for(k=0;k<=z;k++)
			{
				if(i==0&&j==0&&k!=0)
				sum[i][j][k]=sum[i][j][k-1]*10+6;
				else if(i==0&&j!=0&&k==0)
				sum[i][j][k]=sum[i][j-1][k]*10+5;
				else if(i!=0&&j==0&&k==0)
				sum[i][j][k]=sum[i-1][j][k]*10+4;
				// cout<<"sum["<<i<<"]["<<j<<"]["<<k<<"] = "<<sum[i][j][k]<<endl;
				// else if(i!=0&&j!=0&&k==0)
				// sum[i][j][k] = (sum[i-1][k][j]*10+4*num[i-1][j][k]);
				
			}
		}
	}
	ll ans=0;
	for(i=0;i<=x;i++)
	{
		for(j=0;j<=y;j++)
		{
			for(k=0;k<=z;k++)
			{
				
				ll p=0;
				if(i>0)
				{
					p = (p+sum[i-1][j][k]*10+4*num[i-1][j][k])%mod;
				}
				if(j>0)
				{
					p = (p+sum[i][j-1][k]*10+5*num[i][j-1][k])%mod;
				}
				if(k>0)
				{
					p = (p+sum[i][j][k-1]*10+6*num[i][j][k-1])%mod;
				}
				if(p!=0)
				sum[i][j][k] = p%mod;
				ans= (ans+sum[i][j][k])%mod;
				// cout<<"sum["<<i<<"]["<<j<<"]["<<k<<"] = "<<sum[i][j][k]<<endl;
			}
		}
	}
	return ans;
	
}
int main() {
	ll i,j,k,l,x,y,z,t;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>z;
		cout<<solve(x,y,z)<<endl;
	}
	// your code goes here
	return 0;
}