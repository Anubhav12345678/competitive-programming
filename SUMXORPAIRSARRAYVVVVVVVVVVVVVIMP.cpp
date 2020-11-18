// An efficient C++ program to compute 
// sum of bitwise OR of all pairs 
#include <bits/stdc++.h> 
using namespace std; 

// Returns sum of bitwise OR 
// of all pairs 
long long int sumXOR(int arr[], int n) 
{ 
	long long int sum = 0; 
	for (int i = 0; i < 32; i++) 
	{ 
		// Count of zeros and ones 
		int zc = 0, oc = 0; 
		
		// Individual sum at each bit position 
		long long int idsum = 0; 
		for (int j = 0; j < n; j++) 
		{ 
			if (arr[j] % 2 == 0) 
				zc++; 
			else
				oc++; 
			arr[j] /= 2; 
		} 
		
		// calculating individual bit sum 
		idsum = oc * zc * (1 << i); 

		// final sum	 
		sum += idsum; 
	} 
	return sum; 
} 

int main() 
{ 
	long long int sum = 0; 
	int arr[] = { 5, 9, 7, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sum = sumXOR(arr, n); 
	cout << sum; 
	return 0; 
} 
