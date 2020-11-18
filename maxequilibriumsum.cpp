// CPP program to find 
// maximum equilibrium sum. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find 
// maximum equilibrium sum. 
int findMaxSum(int arr[], int n) 
{ 
	int sum = accumulate(arr, arr + n, 0); 
	int prefix_sum = 0, res = INT_MIN; 
	for (int i = 0; i < n; i++) 
	{ 
	prefix_sum += arr[i]; 
	if (prefix_sum == sum) 
		res = max(res, prefix_sum); 
	sum -= arr[i]; 
	} 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { -2, 5, 3, 1, 
				2, 6, -4, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findMaxSum(arr, n); 
	return 0; 
} 
