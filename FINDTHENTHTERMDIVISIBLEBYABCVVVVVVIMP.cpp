// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return 
// gcd of a and b 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 

	return gcd(b % a, a); 
} 

// Function to return the lcm of a and b 
int lcm(int a, int b) 
{ 
	return (a * b) / gcd(a, b); 
} 

// Function to return the count of numbers 
// from 1 to num which are divisible by a, b or c 
int divTermCount(int a, int b, int c, int num) 
{ 

	// Calculate number of terms divisible by a and 
	// by b and by c then, remove the terms which is are 
	// divisible by both a and b, both b and c, both 
	// c and a and then add which are divisible by a and 
	// b and c 
	return ((num / a) + (num / b) + (num / c) 
			- (num / lcm(a, b)) 
			- (num / lcm(b, c)) 
			- (num / lcm(a, c)) 
			+ (num / lcm(a, lcm(b, c)))); 
} 

// Function to find the nth term 
// divisible by a, b or c 
// by using binary search 
int findNthTerm(int a, int b, int c, int n) 
{ 

	// Set low to 1 and high to max (a, b, c) * n 
	int low = 1, high = INT_MAX, mid; 

	while (low < high) { 
		mid = low + (high - low) / 2; 

		// If the current term is less than 
		// n then we need to increase low 
		// to mid + 1 
		if (divTermCount(a, b, c, mid) < n) 
			low = mid + 1; 

		// If current term is greater than equal to 
		// n then high = mid 
		else
			high = mid; 
	} 

	return low; 
} 

// Driver code 
int main() 
{ 
	int a = 2, b = 3, c = 5, n = 10; 

	cout << findNthTerm(a, b, c, n); 

	return 0; 
} 
