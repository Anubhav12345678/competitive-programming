// C++ program to find minimum number of deletes required 
// to make all elements same. 
#include<bits/stdc++.h> 
using namespace std; 

// Function to get minimum number of elements to be deleted 
// from array to make array elements equal 
int minDelete(int arr[],int n) 
{ 
	// Create an hash map and store frequencies of all 
	// array elements in it using element as key and 
	// frequency as value 
	unordered_map<int, int> freq; 
	for (int i=0; i<n; i++) 
		freq[arr[i]]++; 

	// Find maximum frequency among all frequencies. 
	int max_freq = INT_MIN; 
	for (auto itr = freq.begin(); itr != freq.end(); itr++) 
		max_freq = max(max_freq, itr->second); 

	// To minimize delete operations, we remove all 
	// elements but the most frequent element. 
	return n - max_freq; 
} 

// Driver program to run the case 
int main() 
{ 
	int arr[] = {4, 3, 4, 4, 2, 4}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << minDelete(arr, n); 
	return 0; 
} 
