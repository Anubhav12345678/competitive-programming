// C++ Program to count pairs 
// whose sum divisible by 'K' 
#include <bits/stdc++.h> 
using namespace std; 

// Program to count pairs whose sum divisible 
// by 'K' 
int countKdivPairs(int A[], int n, int K) 
{ 
	// Create a frequency array to count 
	// occurrences of all remainders when 
	// divided by K 
	int freq[K] = { 0 }; 

	// To store count of pairs. 
	int ans = 0; 

	// Traverse the array, compute the remainder 
	// and add k-remainder value hash count to ans 
	for (int i = 0; i < n; i++) { 
		int rem = A[i] % K; 
		if (rem != 0) 
			ans += freq[K - rem]; 
		else
			ans += freq[0]; 

		// Increment count of remainder in hash map 
		freq[rem]++; 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 

	int A[] = { 2, 2, 1, 7, 5, 3 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	int K = 4; 
	cout << countKdivPairs(A, n, K); 

	return 0; 
} 
