#include <bits/stdc++.h> 
using namespace std; 

// Function to find minimum XOR pair 
int minXOR(int arr[], int n) 
{ 
	// Sort given array 
	sort(arr, arr + n); 

	int minXor = INT_MAX; 
	int val = 0; 

	// calculate min xor of consecutive pairs 
	for (int i = 0; i < n - 1; i++) { 
		val = arr[i] ^ arr[i + 1]; 
		minXor = min(minXor, val); 
	} 

	return minXor; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 9, 5, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << minXOR(arr, n) << endl; 

	return 0; 
} 
