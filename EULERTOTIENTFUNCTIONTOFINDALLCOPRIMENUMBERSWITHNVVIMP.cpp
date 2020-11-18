// C program to calculate Euler's Totient Function 
// using Euler's product formula 
/*
Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n,
 i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
A simple solution is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.
 Below is the implementation of the simple method to compute Euler’s Totient function for an input integer n.
The above code calls gcd function O(n) times. Time complexity of the gcd function is O(h) where h is number of 
digits in smaller number of given two numbers. Therefore, an upper bound on time complexity of above solution is 
O(nLogn) [How? there can be at most Log10n digits in all numbers from 1 to n]

Below is a Better Solution. The idea is based on Euler’s product formula which states that value of totient functions
 is below product over all prime factors p of n.
eulersproduct
The formula basically says that the value of ?(n) is equal to n multiplied by product of (1 – 1/p) for all prime factors
 p of n. For example value of ?(6) = 6 * (1-1/2) * (1 – 1/3) = 2.
 geeksforgeeks.org/eulers-totient-function/
*/
#include <stdio.h> 

int phi(int n) 
{ 
	float result = n; // Initialize result as n 

	// Consider all prime factors of n and for every prime 
	// factor p, multiply result with (1 - 1/p) 
	for (int p = 2; p * p <= n; ++p) { 
		
		// Check if p is a prime factor. 
		if (n % p == 0) { 
			
			// If yes, then update n and result 
			while (n % p == 0) 
				n /= p; 
			result *= (1.0 - (1.0 / (float)p)); 
		} 
	} 

	// If n has a prime factor greater than sqrt(n) 
	// (There can be at-most one such prime factor) 
	if (n > 1) 
		result *= (1.0 - (1.0 / (float)n)); 

	return (int)result; 
} 

// Driver program to test above function 
int main() 
{ 
	int n; 
	for (n = 1; n <= 10; n++) 
		printf("phi(%d) = %d\n", n, phi(n)); 
	return 0; 
} 
