// C++ program to get updated array after many array range 
// add operation 
#include <bits/stdc++.h> 
using namespace std; 

// Utility method to add value val, to range [lo, hi] 
void add(int arr[], int N, int lo, int hi, int val) 
{ 
	arr[lo] += val; 
	if (hi != N - 1) 
	arr[hi + 1] -= val; 
} 

// Utility method to get actual array from operation array 
void updateArray(int arr[], int N) 
{ 
	// convert array into prefix sum array 
	for (int i = 1; i < N; i++) 
		arr[i] += arr[i - 1]; 
} 

// method to print final updated array 
void printArr(int arr[], int N) 
{ 
	updateArray(arr, N); 
	for (int i = 0; i < N; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code to test above methods 
int main() 
{ 
	int N = 6; 

	int arr[N] = {0}; 

	// Range add Queries 
	add(arr, N, 0, 2, 100); 
	add(arr, N, 1, 5, 100); 
	add(arr, N, 2, 3, 100); 

	printArr(arr, N); 
	return 0; 
} 
