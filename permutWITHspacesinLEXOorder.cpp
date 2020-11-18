#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
void printpatterutil(char s[],char buff[],ll i,ll j,ll n)
{
	if(i==n)
	{
		buff[j] = '\0';
		cout<<"("<<buff<<")";
		return;
	}
	
	buff[j] = ' ';
	buff[j+1] = s[i];
	printpatterutil(s,buff,i+1,j+2,n);
	
	buff[j] = s[i];//put the char
	 printpatterutil(s,buff,i+1,j+1,n);
	//or
	// put space first and then put cur char
	// buff[j] = ' ';
	// buff[j+1] = s[i];
	// printpatterutil(s,buff,i+1,j+2,n);
}
void prinepttern(char s[])
{
	ll n = strlen(s);
	char buff[2*n];// to store the output strngs as max len of res str can be 2*n-1; we have 1 extra for null char 
    buff[0] = s[0];// first chat will always be at the first pos
    printpatterutil(s,buff,1,1,n);
	
	
}
int main() {
	ll t,i,j,k;
	char s[101];
	cin>>t;
	while(t--)
	{
		cin>>s;
		prinepttern(s);
		cout<<"\n";
	}
	
	// your code goes here
	return 0;
}