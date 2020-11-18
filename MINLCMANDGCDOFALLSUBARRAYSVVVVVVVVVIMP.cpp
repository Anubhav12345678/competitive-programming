// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return minimum GCD 
// among all subarrays 
int minGCD(int arr[], int n) 
{ 

	int minGCD = 0; 

	// Minimum GCD among all sub-arrays will be 
	// the GCD of all the elements of the array 
	for (int i = 0; i < n; i++) 
		minGCD = __gcd(minGCD, arr[i]); 

	return minGCD; 
} 

// Function to return minimum LCM 
// among all subarrays 
int minLCM(int arr[], int n) 
{ 

	int minLCM = arr[0]; 

	// Minimum LCM among all sub-arrays will be 
	// the minimum element from the array 
	for (int i = 1; i < n; i++) 
		minLCM = min(minLCM, arr[i]); 

	return minLCM; 
} 

// Driver code 
int main() 
{ 

	int arr[] = { 2, 66, 14, 521 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "LCM = " << minLCM(arr, n) 
		<< ", GCD = " << minGCD(arr, n); 

	return 0; 
} 
