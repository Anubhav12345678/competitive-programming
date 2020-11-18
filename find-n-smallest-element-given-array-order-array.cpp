// CPP for printing smallest n number in order 
#include <algorithm> 
#include <iostream> 
using namespace std; 

// Function to print smallest n numbers 
void printSmall(int arr[], int asize, int n) 
{ 
	// Make copy of array 
	vector<int> copy_arr(arr, arr + asize); 

	// Sort copy array 
	sort(copy_arr.begin(), copy_arr.begin() + asize); 

	// For each arr[i] find whether 
	// it is a part of n-smallest 
	// with binary search 
	for (int i = 0; i < asize; ++i) 
		if (binary_search(copy_arr.begin(), 
				copy_arr.begin() + n, arr[i])) 
			cout << arr[i] << " "; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
	int asize = sizeof(arr) / sizeof(arr[0]);	 
	int n = 5; 
	printSmall(arr, asize, n); 
	return 0; 
} 
