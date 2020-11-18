#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
// O(n^2) method
void printlps(string s)  //print longest palindromic substring
{
	ll maxlength =0;
	ll n = s.size();
	ll i=0,j=0,k=0;
	bool table[n][n];
	memset(table,0,sizeof(table));
	for(i=0;i<n;i++)
	table[i][i]=1;
	maxlength = 1;
	ll start = 0;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			table[i][i+1] = 1;
			start=i;
			maxlength=2;
		}
	}
	// checking for substrings of length graeter than 2
	for(k=3;k<=n;k++)
	{
		for(i=0;i<n-k+1;i++)//fixing starting index
		{
			j = i+k-1;//fixing ending index
			if(table[i+1][j-1]&&s[i]==s[j])
			{
				table[i][j]=1;
//				start=i;
				if(maxlength<k)
				{
					start=i;
				maxlength=k;
			    }
			}
		}
	}
	for(i=start;i<=start+maxlength-1;i++)
	cout<<s[i];
	cout<<endl;
	
}
int main()
{
	ll t;
	string s;
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>s;
		printlps(s);
	}
}