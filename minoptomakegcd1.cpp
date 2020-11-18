// CPP program to find minimum GCD operations 
// to make all array elements one. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count number of moves. 
int minimumMoves(int A[], int N) 
{ 
// Counting Number of ones. 
	int one = 0; 
	for (int i = 0; i < N; i++) 
		if (A[i] == 1) 
			one++; 

	// If there is a one 
	if (one != 0) 
		return N - one; 
	
	// Find smallest subarray with GCD equals 
	// to one. 
	int minimum = INT_MAX; 
	for (int i = 0; i < N; i++) { 
		int g = A[i]; // to calculate GCD 
		for (int j = i + 1; j < N; j++) { 
			g = __gcd(A[j], g); 
			if (g == 1) { 
				minimum = min(minimum, j - i); 
				break; 
			} 
		} 
	} 

	if (minimum == INT_MAX) // Not Possible 
		return -1; 
	else
		return N + minimum - 1; // Final answer 
} 

// Driver code 
int main() 
{ 
	int A[] = { 2, 4, 3, 9 }; 
	int N = sizeof(A) / sizeof(A[0]); 
	cout << minimumMoves(A, N); 
	return 0; 
} 
