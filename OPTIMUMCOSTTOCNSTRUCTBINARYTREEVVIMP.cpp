#include<bits/stdc++.h>
using namespace std;
int solve(int freq[],int i,int j,int lvl,map<string,int> &lookup)
{
	if(j>i)
		return 0;
	string key = to_string(i)+"|"+to_string(j)+"|"to_string(lvl);
	if(lookup.find(k)==lookup.end())
	{
		lookup[key] = INT_MAX;
		for(int k=i;k<=j;k++)
		{
			int left = solve(freq,i,k-1,lvl+1,lookup);
			int right = solve(freq,k+1,j,lvl+1,lookup);
			lookup[key] = min(lookup[key],freq[k]*lvl+left+right);
		}
	}
	return lookup[key];
}
int main()
{
	int freq[] = {25,20,30};
	int n=3;
	map<string,int> lookup;

	cout<<"OPTIMUM COST IS"<<solve(freq,0,n-1,1,lookup);
}







