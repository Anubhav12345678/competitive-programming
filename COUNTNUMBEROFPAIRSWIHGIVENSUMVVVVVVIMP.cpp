// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count of pairs 
// from arr[] with the given sum 
int pairs_count(int arr[], int n, int sum) 
{ 
	// To store the count of pairs 
	int ans = 0; 

	// Sort the given array 
	sort(arr, arr + n); 

	// Take two pointers 
	int i = 0, j = n - 1; 

	while (i < j) { 
		// If sum is greater 
		if (arr[i] + arr[j] < sum) 
			i++; 

		// If sum is lesser 
		else if (arr[i] + arr[j] > sum) 
			j--; 

		// If sum is equal 
		else { 
			// Find the frequency of arr[i] 
			int x = arr[i], xx = i; 
			while (i < j and arr[i] == x) 
				i++; 

			// Find the frequency of arr[j] 
			int y = arr[j], yy = j; 
			while (j >= i and arr[j] == y) 
				j--; 

			// If arr[i] and arr[j] are same 
			// then remove the extra number counted 
			if (x == y) { 
				int temp = i - xx + yy - j - 1; 
				ans += (temp * (temp + 1)) / 2; 
			} 
			else
				ans += (i - xx) * (yy - j); 
		} 
	} 

	// Return the required answer 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 5, 7, 5, -1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int sum = 6; 

	cout << pairs_count(arr, n, sum); 

	return 0; 
} 
