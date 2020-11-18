#include <bits/stdc++.h>
using namespace std;
#define ll long long
//description is given below
ll solve(ll x)
{
	ll cnt=0;
	while(x%2==0)
	{
	x/=2;
	cnt+=1;
	}
	for(ll i=3;i*i<=x;i+=2)
	{
		while(x%i==0)
		{
			x/=i;
			cnt++;
		}
	}
	if(x>1)
	cnt++;
	return cnt;
	
}
int main() {
	ll t,x,k;
	cin>>t;
	while(t--)
	{
		cin>>x>>k;
		ll s = solve(x);
		if(s>=k)
		cout<<"1\n";
		else
		cout<<"0"<<endl;
	}
	// your code goes here
	return 0;
}

/*
When Varsha was travelling home, she saw a mysterious villa. Varsha is curious about this strange villa and wants to explore it. When she reached the entry gate, the guard gave her a problem to solve and said that he would allow her to enter the villa only if she solved it.

The guard gave Varsha two integers X and K. Varsha needs to determine whether there is an integer A such that it has exactly X positive integer divisors and exactly K of them are prime numbers.

Varsha found this problem really hard to solve. Can you help her?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers X and K.
Output
For each test case, print a single line containing one integer: 1 if a valid integer A exists or 0 if it does not exist.

Constraints
1≤T≤103
1≤X,K≤109
Subtasks
Subtask #1 (15 points):

T≤100
K≤2
Subtask #2 (85 points): original constraints

Example Input
1
4 2
Example Output
1
*/