#include<bits/stdc++.h>
using namespace std;
//to cal xor of a&b if both bits are on or off the result is false else the result is true
// xor of a numberand 0 is the number itself
ll myxor(ll a,ll b)
{
  bool b1,b2,xoredbit;
  ll res=0;
  for(ll i = 31;i>=0;i--)//assuming 32 bit integer
  {
  	b1 = a&(1<<i);
  	b2 = b&(1<<i);
  	xoredbit = (b1&b2)?0:(b1|b2);
  	res<<=1;
  	res |=xoredbit;
  }
  return res;
}
int main(int argc, char const *argv[])
{
	cout<<myxor(5,3);
	return 0;
}