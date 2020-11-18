// CPP Program to find the maximum subset 
// with bitwise OR equal to k 
#include <bits/stdc++.h> 
using namespace std; 

// function to find the maximum subset with 
// bitwise OR equal to k 
void subsetBitwiseORk(int arr[], int n, int k) 
{ 
	vector<int> v; 

	for (int i = 0; i < n; i++) { 

		// If the bitwise OR of k and element 
		// is equal to k, then include that element 
		// in the subset 
		if ((arr[i] | k) == k) 
			v.push_back(arr[i]); 
	} 

	// Store the bitwise OR of elements in v 
	int ans = 0; 

	for (int i = 0; i < v.size(); i++) 
		ans |= v[i]; 

	// If ans is not equal to k, subset doesn't exist 
	if (ans != k) { 
		cout << "Subset does not exist" << endl; 
		return; 
	} 

	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << ' '; 
} 

// Driver Code 
int main() 
{ 
	int k = 3; 
	int arr[] = { 1, 4, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	subsetBitwiseORk(arr, n, k); 
	return 0; 
} 
