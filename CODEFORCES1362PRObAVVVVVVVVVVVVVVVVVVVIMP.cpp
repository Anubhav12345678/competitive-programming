#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Johnny has recently found an ancient, broken computer. The machine has only one register, 
which allows one to put in there one variable. Then in one operation, you can shift its bits 
left or right by at most three positions. The right shift is forbidden if it cuts off some ones.
 So, in fact, in one operation, you can multiply or divide your number by 2, 4 or 8, and division 
 is only allowed if the number is divisible by the chosen divisor.

Formally, if the register contains a positive integer x, in one operation it can be replaced by one of the following:

x⋅2
x⋅4
x⋅8
x/2, if x is divisible by 2
x/4, if x is divisible by 4
x/8, if x is divisible by 8
For example, if x=6, in one operation it can be replaced by 12, 24, 48 or 3. Value 6 isn't divisible
 by 4 or 8, so there're only four variants of replacement.

Now Johnny wonders how many operations he needs to perform if he puts a in the register and wants to get b at the end.




*/
ll solve(ll a,ll b)
{
	ll x=0,y=0;
	while(a%2==0)
	{
		a/=2;
		x++;
	}
	while(b%2==0)
	{
		b/=2;
		y++;
	}
	if(a!=b)
	return -1;
	ll t = abs(x-y)/3;
	if(abs(x-y)%3!=0)
	t++;
	return t;
}
int main() {
	ll t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
	// your code goes here
	return 0;
}