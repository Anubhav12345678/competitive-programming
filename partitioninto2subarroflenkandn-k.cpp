// CPP program to calculate max_difference between 
// the sum of two subarrays of length k and N - k 
#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate max_difference 
int maxDifference(int arr[], int N, int k) 
{ 
	int M, S = 0, S1 = 0, max_difference = 0; 

	// Sum of the array 
	for (int i = 0; i < N; i++) 
		S += arr[i]; 

	// Sort the array in descending order 
	sort(arr, arr + N, greater<int>()); 
	M = max(k, N - k); 
	for (int i = 0; i < M; i++) 
		S1 += arr[i]; 

	// Calculating max_difference 
	max_difference = S1 - (S - S1); 
	return max_difference; 
} 

// Driver function 
int main() 
{ 
	int arr[] = { 8, 4, 5, 2, 10 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	int k = 2; 
	cout << maxDifference(arr, N, k) << endl; 
	return 0; 
} 
