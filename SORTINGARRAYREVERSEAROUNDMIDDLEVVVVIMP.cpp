// CPP program to find possibility to sort 
// by multiple subarray reverse operarion 
#include <bits/stdc++.h> 
using namespace std; 

bool ifPossible(int arr[], int n) 
{ 
	int cp[n]; 

	// making the copy of the original array 
	copy(arr, arr + n, cp); 

	// sorting the copied array 
	sort(cp, cp + n); 

	for (int i = 0; i < n; i++) { 

		// checking mirror image of elements of sorted 
		// copy array and equivalent element of original 
		// array 
		if (!(arr[i] == cp[i]) && !(arr[n - 1 - i] == cp[i])) 
			return false; 
	} 

	return true; 
} 

// driver code 
int main() 
{ 
	int arr[] = { 1, 7, 6, 4, 5, 3, 2, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (ifPossible(arr, n)) 
	cout << "Yes"; 
	else
	cout << "No"; 

	return 0; 
} 
