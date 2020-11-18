//MEEEEEINTERVIEWBIT
#include<bits/stdc++.h>
using namespace std;
#include<map>
#define mod 1000000007
#define ll long  long int
ll lookup[1001][5001];
ll cnt(ll n,ll s)
{
    if(n==0)
    return s==0;
    if(lookup[n][s]!=-1)
    return lookup[n][s];
    ll ans=0;
    for(ll i=0LL;i<10;i++)
    {
        if(s-i>=0)
        ans = (ans+cnt(n-1,s-i))%mod;
    }
    return lookup[n][s] = ans;
    
}
ll find(ll n,ll s)
{
    memset(lookup,-1,sizeof(lookup));
    ll ans=0LL;
    for(ll i=1;i<=9;i++){
        if(s-i>=0)
        ans= (ans+cnt(n-1,s-i))%mod;
    }
    return ans%mod;
}
int Solution::solve(int n, int s) {
    return (int)find((long long int)n,(long long int)s)%mod;
}

















// A C++ memoization based recursive program to count 
// numbers with sum of n as given 'sum' 
#include<bits/stdc++.h> 
using namespace std; 

// A lookup table used for memoization 
unsigned long long int lookup[101][501]; 

// Memoization based implementation of recursive 
// function 
unsigned long long int countRec(int n, int sum) 
{ 
	// Base case 
	if (n == 0) 
	return sum == 0; 

	// If this subproblem is already evaluated, 
	// return the evaluated value 
	if (lookup[n][sum] != -1) 
	return lookup[n][sum]; 

	// Initialize answer 
	unsigned long long int ans = 0; 

	// Traverse through every digit and 
	// recursively count numbers beginning 
	// with it 
	for (int i=0; i<10; i++) 
	if (sum-i >= 0) 
		ans += countRec(n-1, sum-i); 

	return lookup[n][sum] = ans; 
} 

// This is mainly a wrapper over countRec. It 
// explicitly handles leading digit and calls 
// countRec() for remaining n. 
unsigned long long int finalCount(int n, int sum) 
{ 
	// Initialize all entries of lookup table 
	memset(lookup, -1, sizeof lookup); 

	// Initialize final answer 
	unsigned long long int ans = 0; 

	// Traverse through every digit from 1 to 
	// 9 and count numbers beginning with it 
	for (int i = 1; i <= 9; i++) 
	if (sum-i >= 0) 
		ans += countRec(n-1, sum-i); 
	return ans; 
} 

// Driver program 
int main() 
{ 
	int n = 3, sum = 5; 
	cout << finalCount(n, sum); 
	return 0; 
} 
