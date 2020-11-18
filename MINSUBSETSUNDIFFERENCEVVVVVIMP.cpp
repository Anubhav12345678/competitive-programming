#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define ll long long
#define pb push_back
int solve(vector<int> &v)
{
	int n = v.size();
	int s=0,i,j,k,l;
	for(i=0;i<n;i++)
		s+=v[i];
	bool t[n+1][s+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			if(i==0)
				t[i][j]=0;
			else if(j==0)
				t[i][j]=1;
			else if(v[i-1]<=j)
				t[i][j] = t[i-1][j]||t[i-1][j-v[i-1]];// we can include or exclude that ele
			else
				t[i][j] = t[i-1][j];// excluding that eles
		}
	}
	int ans=1e9+7;// min diff;
	for(i=0;i<=s/2;i++)
	{
		if(t[n][i])
			ans = min(ans,s-2*i);
	}
	return ans;

}
int main()
{
	int n,i,j,k,l;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<"min subset sum diff is"<<solve(v);
}






