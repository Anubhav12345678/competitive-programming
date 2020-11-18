// A hashing based solution to find the 
// minimum number of subsets of a set 
// such that every subset contains distinct 
// elements. 
#include <bits/stdc++.h> 
using namespace std; 
//We basically need to find the most frequent element in the array. The result is equal to the frequency of the most frequent element.
// Function to count subsets such that all 
// subsets have distinct elements. 
int subset(int arr[], int n) 
{ 
	// Traverse the input array and 
	// store frequencies of elements 
	unordered_map<int, int> mp;	 
	for (int i = 0; i < n; i++) 
		mp[arr[i]]++; 
	
	// Find the maximum value in map. 
	int res = 0; 
	for (auto x : mp) 
	res = max(res, x.second); 

	return res; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 5, 6, 9, 3, 4, 3, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << subset(arr, n); 
	return 0; 
} 
