#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define e endl;
#include<string.h>
ll longestsubstring(char s[])
{
	ll visited[257];
	memset(visited,-1,sizeof(visited));
	ll n= strlen(s);
	ll i,j,start=0,cur_len=0,maxlen=0;
	for(i=0;i<n;i++)
	{
		char c=s[i];
		  /* If the currentt character is not present in the  
        already processed substring or it is not part of  
        the current NRCS(Non repeating current substring), then do cur_len++ */
		if(visited[c]!=-1&&visited[c]>=start)
		{
			start = visited[c]+1;
		}
		visited[c]=i;
		maxlen = max(maxlen,i-start+1);
		// cout<<i<<" "<<start<<" "<<maxlen<<endl;
	}
	return maxlen;
}
int main() {
	ll t;
	char s[10005];
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<longestsubstring(s)<<e;
	}
	// your code goes here
	return 0;
}