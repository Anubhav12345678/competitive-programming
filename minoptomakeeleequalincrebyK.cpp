// Program to make all array equal 
#include <bits/stdc++.h> 
using namespace std; 

// function for calculating min operations 
int minOps(int arr[], int n, int k) 
{ 
	// max elements of array 
	int max = *max_element(arr, arr + n); 
	int res = 0; 

	// iterate for all elements 
	for (int i = 0; i < n; i++) { 

		// check if element can make equal to 
		// max or not if not then return -1 
		if ((max - arr[i]) % k != 0) 
			return -1; 

		// else update res for required operations 
		else
			res += (max - arr[i]) / k; 
	} 

	// return result 
	return res; 
} 

// driver program 
int main() 
{ 
	int arr[] = { 21, 33, 9, 45, 63 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 6; 
	cout << minOps(arr, n, k); 
	return 0; 
} 
