#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
}
ll convert(string s)
{
	ll l = s.size();
	ll i=0,s1,s2,res=0;
	for(i=0;i<l;i++)
	{
		s1=value(s[i]);
		if(i+1<l)
		{
			s2 = value(s[i+1]);
			if(s1>=s2)
			{
			 res+=s1;	
			}
			else
			{
				res = res + s2-s1;
				i++;
			}
		}
		else
		{
			res+=s1;
		}
		// cout<<res<<endl;
	}
	return res;
	
}
int main() {
	ll t;
	string s;
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>s;
		cout<<convert(s)<<endl;
	}
	
	
	// your code goes here
	return 0;
}