// A C++ program to put positive 
// numbers at even indexes (0, 2, 4,..) 
// and negative numbers at odd 
// indexes (1, 3, 5, ..) 
#include <iostream> 
using namespace std; 

class GFG 
{ 
	public: 
	void rearrange(int [],int); 
	void swap(int *,int *); 
	void printArray(int [],int); 
}; 

// The main function that rearranges 
// elements of given array. It puts 
// positive elements at even indexes 
// (0, 2, ..) and negative numbers 
// at odd indexes (1, 3, ..). 
void GFG :: rearrange(int arr[], int n) 
{ 
	// The following few lines are 
	// similar to partition process 
	// of QuickSort. The idea is to 
	// consider 0 as pivot and 
	// divide the array around it. 
	int i = -1; 
	for (int j = 0; j < n; j++) 
	{ 
		if (arr[j] < 0) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 

	// Now all positive numbers are at 
	// end and negative numbers at the 
	// beginning of array. Initialize 
	// indexes for starting point of 
	// positive and negative numbers 
	// to be swapped 
	int pos = i + 1, neg = 0; 

	// Increment the negative index by 
	// 2 and positive index by 1, 
	// i.e., swap every alternate negative 
	// number with next positive number 
	while (pos < n && neg < pos && 
					arr[neg] < 0) 
	{ 
		swap(&arr[neg], &arr[pos]); 
		pos++; 
		neg += 2; 
	} 
} 

// A utility function 
// to swap two elements 
void GFG :: swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// A utility function to print an array 
void GFG :: printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {-1, 2, -3, 4, 
				5, 6, -7, 8, 9}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	GFG test; 
	test.rearrange(arr, n); 
	test.printArray(arr, n); 
	return 0; 
} 

// This code is contributed 
// by vt_Yogesh Shukla 1 

//meeeee
// C++ program to rearrange array in alternating 
// positive & negative items with O(1) extra space 
#include <bits/stdc++.h> 
using namespace std; 

// Function to rearrange positive and negative 
// integers in alternate fashion. The below 
// solution doesn't maintain original order of 
// elements 
void rearrange(int arr[], int n) 
{ 
	int i = -1, j = n; 

	// shift all negative values to the end 
	while (i < j) 
	{ 
		while (arr[++i] > 0); 
		while (arr[--j] < 0); 
		if (i < j) 
			swap(arr[i], arr[j]); 
	} 

	// i has index of leftmost negative element 
	if (i == 0 || i == n) 
		return; 

	// start with first positive element at index 0 

	// Rearrange array in alternating positive & 
	// negative items 
	int k = 0; 
	while (k < n && i < n) 
	{ 
		// swap next positive element at even position 
		// from next negative element. 
		swap(arr[k], arr[i]); 
		i = i + 1; 
		k = k + 2; 
	} 
} 

// Utility function to print an array 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {2, 3, -4, -1, 6, -9}; 

	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Given array is \n"; 
	printArray(arr, n); 

	rearrange(arr, n); 

	cout << "Rearranged array is \n"; 
	printArray(arr, n); 

	return 0; 
} 

