#include <nits/stdc++.h>
using namespace std;
#define ll long long
void fill(string pat,int n,int lps[])
{
	int i=0,j,k,l,len=0,n;
	n = pat.size();
	lps[0]=0;
	i=1;
	while(i<n)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			len = lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	
}
void kmpsearch(string txt,string pat)
{
	int m = pat.size();
	int n = txt.size();
	int lps[m];
	fill(pat,m,lps);
	int i=0,j=0,k,l;
	while(i<n&&j<m)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		else if(j==n)
		{
			cout<<"pat present at ind "<<i-j<<endl;
			j = lps[j-1];
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			i++;
		}
	}
}
int main() {
	string txt = "ABABDABACDABABCABAB"; 
    string pat = "ABABCABAB"; 
    kmpsearch(txt, pat); 
    return 0;
	// your code goes here
	// return 0;
}