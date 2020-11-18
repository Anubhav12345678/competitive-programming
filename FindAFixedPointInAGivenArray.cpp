
/*

Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is 
any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that 
integers in array can be negative.

Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3 

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0 


  Input: arr[] = {-10, -5, 3, 4, 7, 9}
  Output: -1  // No Fixed Point


*/
// C++ program to check fixed point 
// in an array using binary search 
#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int low, int high) 
{ 
	if(high >= low) 
	{ 
		int mid = (low + high)/2; /*low + (high - low)/2;*/
		if(mid == arr[mid]) 
			return mid; 
		if(mid > arr[mid]) 
			return binarySearch(arr, (mid + 1), high); 
		else
			return binarySearch(arr, low, (mid -1)); 
	} 

	/* Return -1 if there is no Fixed Point */
	return -1; 
} 

/* Driver code */
int main() 
{ 
	int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<"Fixed Point is "<< binarySearch(arr, 0, n-1); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
