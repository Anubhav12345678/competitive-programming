#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)



 

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves

*/
//n’th Catalan Number can also be evaluated using direct formula.

   // T(n) = (2n)! / (n+1)!n!
ll solve(ll n)
{
	ll cat[n+1] = {0};
	cat[0]=1;
	cat[1] = 1;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<i;j++)
		cat[i]+=cat[j]*cat[i-j-1];
	}
	return cat[n];
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
}
// another solution
// C++ program for nth Catalan Number 
#include<iostream> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 

// Driver program to test above functions 
int main() 
{ 
	for (int i = 0; i < 10; i++) 
		cout << catalan(i) << " "; 
	return 0; 
} 
// another method
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;
cpp_int coefficient(int n,int k){
    cpp_int res=1;
    for(int i=0;i<k;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    cpp_int result=coefficient(2*n,n);
    cout<<result/(n+1)<<endl;
    
   }
}