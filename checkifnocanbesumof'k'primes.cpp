// C++ implementation to check if N can be 
// written as sum of k primes 
#include<bits/stdc++.h> 
using namespace std; 
  
// Checking if a number is prime or not 
bool isprime(int x) 
{ 
    // check for numbers from 2 to sqrt(x) 
    // if it is divisble return false 
    for (int i=2; i*i<=x; i++) 
        if (x%i == 0) 
            return false; 
    return true; 
} 
  
// Returns true if N can be written as sum 
// of K primes 
bool isSumOfKprimes(int N, int K) 
{ 
    // N < 2K directly return false 
    if (N < 2*K) 
        return false; 
  
    // If K = 1 return value depends on primality of N 
    if (K == 1) 
        return isprime(N); 
  
    if (K == 2) 
    { 
        // if N is even directly return true; 
        if (N%2 == 0) 
            return true; 
  
        // If N is odd, then one prime must 
        // be 2. All other primes are odd 
        // and cannot have a pair sum as even. 
        return isprime(N - 2); 
    } 
  
    // If K >= 3 return true; 
    return true; 
} 
  
// Driver function 
int main() 
{ 
    int n = 10, k = 2; 
    if (isSumOfKprimes (n, k)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
    return 0; 
} 
