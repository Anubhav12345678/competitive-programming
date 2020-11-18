// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return length 
// of the resulatant number 
int numLen(int K) 
{ 

	// If K is a multiple of 2 or 5 
	if (K % 2 == 0 || K % 5 == 0) 
		return -1; 

	int number = 0; 

	int len = 1; 

	for (len = 1; len <= K; len++) { 

		// Instead of generating all possible numbers 
		// 1, 11, 111, 111, ..., K 1's 
		// Take remainder with K 
		number = (number * 10 + 1) % K; 

		// If number is divisible by k 
		// then remainder will be 0 
		if (number == 0) 
			return len; 
	} 

	return -1; 
} 

// Driver code 
int main() 
{ 

	int K = 7; 
	cout << numLen(K); 

	return 0; 
} 
