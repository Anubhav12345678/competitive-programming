// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count numbers having 
// exactly 9 divisors 
int countNumbers(int n) 
{ 
	int c = 0; 

	int limit = sqrt(n); 

	// Sieve array 
	int prime[limit + 1]; 

	// initially prime[i] = i 
	for (int i = 1; i <= limit; i++) 
		prime[i] = i; 

	// use sieve concept to store the 
	// first prime factor of every number 
	for (int i = 2; i * i <= limit; i++) { 
		if (prime[i] == i) { 
			// mark all factors of i 
			for (int j = i * i; j <= limit; j += i) 
				if (prime[j] == j) 
					prime[j] = i; 
		} 
	} 

	// check for all numbers if they can be 
	// expressed in form p*q 
	for (int i = 2; i <= limit; i++) { 
		// p prime factor 
		int p = prime[i]; 

		// q prime factor 
		int q = prime[i / prime[i]]; 

		// if both prime factors are different 
		// if p*q<=n and q!= 
		if (p * q == i && q != 1 && p != q) { 
			c += 1; 
		} 
		else if (prime[i] == i) { 

			// Check if it can be expressed as p^8 
			if (pow(i, 8) <= n) { 

				c += 1; 
			} 
		} 
	} 

	return c; 
} 

// Driver Code 
int main() 
{ 
	int n = 1000; 

	cout << countNumbers(n); 

return 0; 
} 



//meee
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<math.h>
//fun to find cnt of num <=n hvng num of dividors equal to 9
ll solve(ll n){
	ll i,j,k,l,m,p,q;
	ll lim  =sqrt(n);
	// cout<<"lim = "<<lim<<endl;
	ll prime[lim+1];
	for(i=1;i<=lim;i++)
	prime[i]=i;
	for(i=2;i*i<=lim;i++){
		if(prime[i]==i){
			for(j=i*i;j<=lim;j+=i){
				if(prime[j]==j)
				prime[j]=i;
			}
		}
	}
	
	ll c=0;
	for(i=2;i<=lim;i++){
		p = prime[i];
		q = prime[i/prime[i]];
		if((p*q==i)&&q!=1&&p!=q)
		c++;
		else if(prime[i]==i){
			if(pow(i,8)<=n)
			c++;
		}
	}
	return c;
}
int main() {
	ll n;
	cin>>n;
	cout<<solve(n);
	// your code goes here
	return 0;
}