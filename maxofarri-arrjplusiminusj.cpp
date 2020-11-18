// Efficient CPP program to find maximum value 
// of |arr[i] - arr[j]| + |i - j| 
#include <bits/stdc++.h> 
using namespace std; 

// Return maximum |arr[i] - arr[j]| + |i - j| 
int findValue(int arr[], int n) 
{ 
	int a[n], b[n], tmp; 

	// Calculating first_array and second_array 
	for (int i = 0; i < n; i++) { 
		a[i] = (arr[i] + i); 
		b[i] = (arr[i] - i); 
	} 

	int x = a[0], y = a[0]; 

	// Finding maximum and minimum value in 
	// first_array 
	for (int i = 0; i < n; i++) { 
		if (a[i] > x) 
			x = a[i]; 

		if (a[i] < y) 
			y = a[i]; 
	} 

	// Storing the difference between maximum and 
	// minimum value in first_array 
	int ans1 = (x - y); 

	x = b[0]; 
	y = b[0]; 

	// Finding maximum and minimum value in 
	// second_array 
	for (int i = 0; i < n; i++) { 
		if (b[i] > x) 
			x = b[i]; 

		if (b[i] < y) 
			y = b[i]; 
	} 

	// Storing the difference between maximum and 
	// minimum value in second_array 
	int ans2 = (x - y); 

	return max(ans1, ans2); 
} 

// Driven Program 
int main() 
{ 
	int arr[] = { 1, 2, 3, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << findValue(arr, n) << endl; 

	return 0; 
} 
