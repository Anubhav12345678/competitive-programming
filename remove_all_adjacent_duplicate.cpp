#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
//O(n^2) sol
// O(n) sol to be done
//remove all adjacent duplicate
int main(int argc, char const *argv[])
{
	string s;
	ll t,i,j,k,l;
	cin>>t;
	getchar();
	while(t--)
	{
//		getchar();
		cin>>s;
        l = s.size();
        ll f[l];
        memset(f,0,sizeof(f));
        for(i=0;i<l-1;)
        	{
        		if(s[i]==s[i+1])
        		{
        			while(s[i]==s[i+1])
        			{
        				f[i]=1;
        				f[i+1]=1;
                        i++;
        			}
        		}
        		else
        		i++;
        	}
        for(i=0;i<l;i++)
         if(f[i]==0)
         cout<<s[i];
        cout<<endl;
	}
	return 0;
}

//O(n) sol
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void 







