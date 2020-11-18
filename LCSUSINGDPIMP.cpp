#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
// complexity is O(mn)
ll LCS(char s1[],char s2[])
{
	ll i,j;
	ll m = strlen(s1);
	ll n = strlen(s2);
	ll l[n+1][m+1];
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			l[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			l[i][j] = l[i-1][j-1]+1;
			else
			l[i][j] = max(l[i-1][j],l[i][j-1]);
		}
	}
	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return l[m][n];
}
int main() {
	char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
   
  ll m = strlen(X); 
  ll n = strlen(Y); 
   
  printf("Length of LCS is %lld", LCS( X, Y ) ); 
  
  return 0;
	// your code goes here
	return 0;
}