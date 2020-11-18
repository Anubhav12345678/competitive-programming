#include <bits/stdc++.h>
using namespace std;
#define ll long long
void majority(ll p,ll q,bool *a,ll n)
{
	ll ar[p],i,j,k,l;
	ll st=0,strt=0,en=q,end=0,one=0;
	k=0;
	while(k<p)
	{
		one=0;
		for(i=st;i<en;i++)
		if(a[i]==1)
		one++;
		ar[k++]=one;
		st = en;
		en = en+q;
	}
	strt=0;
	end=q;
	bool found=0;
	while(end>0)
	{
		ll discnt=0;
		for(i=0;i<p;i++)
		if(ar[i]>q/2)
		discnt++;
		if(discnt>p/2)
		{
			cout<<"Yes\n";
			found=1;
			return;
		}
		strt--;
		end--;
		if(strt<0)
		strt=n+strt;
		st=strt,en=end;
		ll l=0;
		while(en<n)
		{
			if(a[st%n]!=a[en%n])
			{
				if(a[st%n]==1)
				ar[l]++;
				else
				ar[l]--;
			}
			l++;
			st = st+q;
			en =en+q;
		}
		
		
	}
	if(found==0)
	{
		cout<<"NO\n";
		return;
	}
}
int main() {
 int p = 3, q = 3; 
    int n = p * q; 
  
    bool a[] = { 0, 0, 1, 1, 0, 1, 1, 0, 0 }; 
  
    // circular array of given size 
    majority(p, q, a, n); 
  
    return 0;
}