// An efficient C++ program to check Bleak Number 
#include <bits/stdc++.h> 
using namespace std; 
/*A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e.,
 x + countSetBits(x) is not equal to n for any non-negative number x.*/
/* Function to get no of set bits in binary 
representation of passed binary no. */
int countSetBits(int x) 
{ 
	unsigned int count = 0; 
	while (x) { 
		x &= (x - 1); 
		count++; 
	} 
	return count; 
} 

// A function to return ceiling of log x 
// in base 2. For example, it returns 3 
// for 8 and 4 for 9. 
int ceilLog2(int x) 
{ 
	int count = 0; 
	x--; 
	while (x > 0) { 
		x = x >> 1; 
		count++; 
	} 
	return count; 
} 

// Returns true if n is Bleak 
bool isBleak(int n) 
{ 
	// Check for all numbers 'x' smaller 
	// than n. If x + countSetBits(x) 
	// becomes n, then n can't be Bleak 
	for (int x = n - ceilLog2(n); x < n; x++) 
		if (x + countSetBits(x) == n) 
			return false; 

	return true; 
} 

// Driver code 
int main() 
{ 
	isBleak(3) ? cout << "Yes\n" : cout << "No\n"; 
	isBleak(4) ? cout << "Yes\n" : cout << "No\n"; 
	return 0; 
} 
