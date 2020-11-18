#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
void solve(string s)
{
	ll i,j,k,nonextd=0,lastentry=0,curmax=0;;
	for(i=0;i<s.size();i++)
	{
		nonextd=0;
		switch(s[i])
		{
			case 'I':
			   j=i+1;
			   while(s[j]=='D'&&j<s.size())
			   {
			   	nonextd++;
			   	j++;
			   }
			   if(i==0)
			   {
			   	curmax = nonextd+2;
			   	cout<<++lastentry;
			   	cout<<curmax;
			   	lastentry = curmax;
			   }
			   else
			   {
			   	 curmax+=nonextd+1;
			   	 lastentry = curmax;
			   	 cout<<lastentry;
			   }
			   for(k=0;k<nonextd;k++)
			   {
			   	cout<<--lastentry;
			   	i++;
			   }
			   break;
			case 'D':
			   if(i==0)
			   {
			   	 j=i+1;
			   while(s[j]=='D'&&j<s.size())
			    {
			   	 nonextd++;
			   	 j++;
			    }
			    
			    curmax = nonextd+2;
			    cout<<curmax<<curmax-1;
			    lastentry = curmax-1;
			    
			   }
			    else
               { 
                // If current 'D' is not first letter 
  
                // Decrement last_entry 
                cout << lastentry - 1; 
                lastentry--; 
               } 
               break; 
		}
	}
	cout<<endl;
	
}
int main() {
	string s;
	ll t;
	cin>>t;
	while(t--)
	{
	    cin>>s;
	    solve(s);
	}
	return 0;
}