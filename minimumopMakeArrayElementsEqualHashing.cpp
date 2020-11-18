// CPP program to find the minimum number of 
// operations required to make all elements 
// of array equal 
#include <bits/stdc++.h> 
using namespace std; 

// function for min operation 
int minOperation (int arr[], int n) 
{ 
	// Insert all elements in hash. 
	unordered_map<int, int> hash; 
	for (int i=0; i<n; i++) 
		hash[arr[i]]++; 

	// find the max frequency 
	int max_count = 0; 
	for (auto i : hash) 
		if (max_count < i.second) 
			max_count = i.second; 

	// return result 
	return (n - max_count); 
} 

// driver program 
int main() 
{ 
	int arr[] = {1, 5, 2, 1, 3, 2, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << minOperation(arr, n); 
	return 0; 
} 
