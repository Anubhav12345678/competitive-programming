#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
int check(char s[],char s1[])
{
	int i,j;
	int n1 = s1.size();
	int n = s.size();
	// to handle the case when n=1||n1=1
	if(n1>=2&&n>=2)
	{
        if(s[0]==s1[n1-2]&&s[1]==s1[n1-1])//clockwise rotate
        {
          i=2;
          j=0;
          while(i<n&&j<n1)
          {
    	      if(s[i]!=s1[j])
    	      	return 0;
          }
        }
        else if(s[n-1]==s1[1]&&s[n-2]==s1[0])//anticlockwise rotate
        {
          i=0;//s
          j=2;//s1
          while(i<n&&j<n1)
    	      if(s[i]!=s1[j])
    		      return 0;
        }
        return 1;
    }
    else
    	return 0;

}
int main(int argc, char const *argv[])
{
	char s[10001],s1[10001];
	int i,j,t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		getchar();
		cin>>s1;
		getchar();
		cout<<check(s,s1)<<endl;
	}
	return 0;
}