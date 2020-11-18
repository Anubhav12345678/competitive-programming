
/*

Mishka wants to buy some food in the nearby shop. Initially, he has s burles on his card.

Mishka can perform the following operation any number of times (possibly, zero): choose some positive integer number 
1≤x≤s, buy food that costs exactly x burles and obtain ⌊x10⌋ burles as a cashback (in other words, Mishka spends x burles
 and obtains ⌊x10⌋ back). The operation ⌊ab⌋ means a divided by b rounded down.

It is guaranteed that you can always buy some food that costs x for any possible value of x.

Your task is to say the maximum number of burles Mishka can spend if he buys food optimally.

For example, if Mishka has s=19 burles then the maximum number of burles he can spend is 21. Firstly, he can spend x=10 burles,
 obtain 1 burle as a cashback. Now he has s=10 burles, so can spend x=10 burles, obtain 1 burle as a cashback and spend it too.

You have to answer t independent test cases.


*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll s)
{
	ll ans=0,i,j,k,l,d=0;
	while(s>=10)
	{
		d=1;
		while((d*10)<=s)
		{
			d*=10;
			// i++;
		}
		// cout<<"s ="<<s<<" d = "<<d<<endl;
		ans+=d;
		s = s-d+(d/10);
		// cout<<"ans = "<<ans<<" s = "<<s<<endl;
	}
	ans+=s;
	return ans;
}
int main() {
	ll t,s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<solve(s)<<endl;
	}
	// your code goes here
	return 0;
}