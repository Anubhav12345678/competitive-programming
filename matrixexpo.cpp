#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
void multiply(ll A[2][2],ll B[2][2])
{
	ll mul[3][3]; 
  for (ll i = 0; i < 2; i++) 
    { 
        for (ll j = 0; j < 2; j++) 
        { 
            mul[i][j] = 0; 
            for (ll k = 0; k < 2; k++) 
                mul[i][j] += A[i][k]*B[k][j]; 
        } 
    }
    for (ll i=0; i<2; i++) 
        for (ll j=0; j<2; j++) 
            A[i][j] = mul[i][j];
}
void power(ll F[2][2],ll n)
{
	ll I[2][2] = {{1,0},{0,1}};
	
	if(n==1)
    multiply(F,I);
	else
	{
		ll M[2][2] = {{1,1},{1,0}};
		power(F,n/2);
		// cout<<"\nn="<<n<<" "<<F[0][0]<<" "<<F[0][1]<<"\n"<<F[1][0]<<" "<<F[1][1]<<"\n\n\n";
		multiply(F,F);
		// cout<<"\nn="<<n<<" "<<F[0][0]<<" "<<F[0][1]<<"\n"<<F[1][0]<<" "<<F[1][1]<<"\n\n\n";
		if(n%2!=0)
		{
		multiply(F,M);
		// cout<<"\nn="<<n<<" "<<F[0][0]<<" "<<F[0][1]<<"\n"<<F[1][0]<<" "<<F[1][1]<<"\n\n\n";
		}
	}
}
ll fib(int n)
{
	if(n==1)
	return 1;
	if(n==2)
	return 1;
	ll F[2][2] = {{1,1},{1,0}};
	power(F,n-1);
	return F[0][0];
}
int main()
{
	ll n,t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	cout<<fib(n)<<endl;
    }
}