// C++ program to check if a given number can be expressed 
// as power 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if n can be written as x^y 
bool isPower(unsigned int n) 
{ 
	// Base case 
	if (n <= 1) return true; 

	// Try all numbers from 2 to sqrt(n) as base 
	for (int x=2; x<=sqrt(n); x++) 
	{ 
		unsigned p = x; 

		// Keep multiplying p with x while is smaller 
		// than or equal to x 
		while (p <= n) 
		{ 
			p *= x; 
			if (p == n) 
				return true; 
		} 
	} 
	return false; 
} 

// Driver Program 
int main() 
{ 
	for (int i =2; i<100; i++) 
		if (isPower(i)) 
		cout << i << " "; 
	return 0; 
} 
