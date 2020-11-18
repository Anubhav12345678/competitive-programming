#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
// ll issubstr(char a[],char b[])
// {
// 	ll n1 = strlen(a);
// 	ll n2 = strlen(b);
// 	ll i=0,j=0,k=0,p=0,u=0;
// 	if(n1>=n2)
// 	{
// 	    for(i=0;i<n1;i++)
// 	    {
// 	    	if(a[i]==b[0])
// 	    	{
// 	    		j=i;
// 	    		k=1;
// 	    		for(;k<n2;k++)
// 	    		{
//     				if(a[j]!=b[k])
// 	    			{
// 	    				k=0;
// 	    				break;
// 	    			}
// 	    			j++;
// 	    		}
// 	    		if(k==n2)
// 	  		    return 1;
// 	  	    }
//   	    }
// 	}
// 	else
// 	{
// 		for(i=0;i<n2;i++)
// 	    {
// 	    	if(b[i]==a[0])
// 	    	{
// 	    		j=i;
// 	    		k=1;
// 	    		for(;k<n1;k++)
// 	    		{
//     				if(b[j]!=a[k])
// 	    			{
// 	    				j=0;
// 	    				k=0;
// 	    				break;
// 	    			}
// 	    			j++;
// 	    		}
// 	    		if(k==n1)
// 	  		    return 1;
// 	  	    }
//   	    }
// 	}
// 	return 0;
// }
// This function returns a pointer points to the first character of the found s2 in s1 otherwise a null pointer if s2 is not 
// present in s1. If s2 points to an empty string, s1 is returned.
int main() {
	ll k,n,i,j,p;
	char s1[101][101];
	char s2[101];
	cin>>k>>n;
	for(i=0;i<k;i++)
	cin>>s1[i];
	while(n--)
	{
		ll f=0;
		cin>>s2;
		if(strlen(s2)>=47)
		{
			cout<<"Good\n";
			continue;
		}
		for(i=0;i<k;i++)
		if(strstr(s2,s1[i]))
		{
			f=1;
			break;
		}
		if(f==0)
		cout<<"Bad\n";
		else
		cout<<"Good\n";
	}
	// your code goes here
	return 0;
}