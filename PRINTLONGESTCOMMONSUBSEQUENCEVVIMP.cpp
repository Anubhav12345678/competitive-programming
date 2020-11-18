#include<bits/stdc++.h>
using namespace std;
#define ll long long
string printlcs(string X,string Y)
{
	int m = X.size();
	int n = Y.size();
	int t[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
				t[i][j]=0;
			else if(X[i-1]==Y[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	string s="";
	i=m,j=n;
	while(i>0&&j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			s.push_back(X[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i-1][j]>t[i][j-1])
				i--;
			else
				j--;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	string x,y;
	cin>>x>>y;
	cout<<"lcs of x and y is"<<printlcs(x,y)<<endl;
}








