// C++ implementation of the above approach 
#include <bits/stdc++.h> 
#define maxLen 30 
using namespace std; 

// Function to find required value 
int findCnt(int arr[], int n, int k) 
{ 
	// Variable to store final answer 
	int ans = 0; 

	// Loop to find prefix-sum 
	for (int i = 1; i < n; i++) { 
		arr[i] += arr[i - 1]; 
		if (arr[i] > k or arr[i] < -1 * k) 
			ans++; 
	} 

	if (arr[0] > k || arr[0] < -1 * k) 
		ans++; 

	// Sorting prefix-sum array 
	sort(arr, arr + n); 

	// Loop to find upper_bound 
	// for each element 
	for (int i = 0; i < n; i++) 
		ans += n - 
	(upper_bound(arr, arr + n, arr[i] + k) - arr); 

	// Returning final answer 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { -1, 4, -5, 6 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 0; 

	// Function to find required value 
	cout << findCnt(arr, n, k); 
} 
