// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print the 
// elements of the array 
void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	cout << endl; 
} 

// Exchange array elements one by 
// one from right to left side 
// starting from the current position 
// and ending at the target position 
void swapMax(int* arr, int target_position, 
					int current_position) 
{ 
	int aux = 0; 
	for (int i = current_position; 
		i > target_position; i--) { 
		aux = arr[i - 1]; 
		arr[i - 1] = arr[i]; 
		arr[i] = aux; 
	} 
} 

// Function to return the 
// maximum number array 
void maximizeArray(int* arr, 
				int length, int swaps) 
{ 
	// Base condition 
	if (swaps == 0) 
		return; 

	// Start from the first index 
	for (int i = 0; i < length; i++) { 
		int max_index = 0, max = INT_MIN; 

		// Search for the next K elements 
		int limit = (swaps + i) > length ? 
						length : swaps + i; 

		// Find index of the maximum 
		// element in next K elements 
		for (int j = i; j <= limit; j++) { 
			if (arr[j] > max) { 
				max = arr[j]; 
				max_index = j; 
			} 
		} 

		// Update the value of 
		// number of swaps 
		swaps -= (max_index - i); 

		// Update the array elements by 
		// swapping adjacent elements 
		swapMax(arr, i, max_index); 

		if (swaps == 0) 
			break; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 9, 8, 1, 4, 9, 9, 9 }; 
	int length = sizeof(arr) / sizeof(int); 
	int swaps = 4; 
	maximizeArray(arr, length, swaps); 

	print(arr, length); 

	return 0; 
} 
