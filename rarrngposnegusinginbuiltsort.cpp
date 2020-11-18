// CPP program to rearrange positive 
// and negative integers keeping 
// order of elements. 
#include <bits/stdc++.h> 
// in O(nlogn)
using namespace std; 

bool comp(int a, int b) 
{ 

// swap not needed 
if((a > 0 && b > 0) || 
(a < 0 && b < 0) || 
(a > 0 && b < 0 )) 
return false; 

// swap needed 
if(a < 0 && b > 0) 
return true; 

// swap not needed 
if((a == 0 && b < 0) || 
(a > 0 && b == 0)) 
return false; 

// swap needed 
if((a == 0 && b > 0) || 
(a < 0 && b == 0)) 
return true; 

} 

void rearrange(int arr[], int n) 
{ 
	sort(arr, arr + n, comp); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { -12, 11, -13, -5, 
				6, -7, 5, -3, -6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	rearrange(arr, n); 
	for (int i = 0; i < n; i++) 
		cout << " " << arr[i]; 

	return 0; 
} 
// below is O(n)
// C++ implementation of the above approach 
#include <iostream> 

void printArray(int array[], int length) 
{ 
	std::cout << "["; 
	
	for(int i = 0; i < length; i++) 
	{ 
		std::cout << array[i]; 
		
		if(i < (length - 1)) 
			std::cout << ", "; 
		else
			std::cout << "]" << std::endl; 
	} 
} 

void reverse(int array[], int start, int end) 
{ 
	while(start < end) 
	{ 
		int temp = array[start]; 
		array[start] = array[end]; 
		array[end] = temp; 
		start++; 
		end--; 
	} 
} 

// Rearrange the array with all negative integers 
// on left and positive integers on right 
// use recursion to split the array with first element 
// as one half and the rest array as another and then 
// merge it with head of the array in each step 
void rearrange(int array[], int start, int end) 
{ 
	// exit condition 
	if(start == end) 
		return; 
	
	// rearrange the array except the first 
	// element in each recursive call 
	rearrange(array, (start + 1), end); 
	
	// If the first element of the array is positive, 
	// then right-rotate the array by one place first 
	// and then reverse the merged array. 
	if(array[start] >= 0) 
	{ 
		reverse(array, (start + 1), end); 
		reverse(array, start, end); 
	} 
} 

// Driver code 
int main() 
{ 
	int array[] = {-12, -11, -13, -5, -6, 7, 5, 3, 6}; 
	int length = (sizeof(array) / sizeof(array[0])); 
	int countNegative = 0; 
	
	for(int i = 0; i < length; i++) 
	{ 
		if(array[i] < 0) 
			countNegative++; 
	} 
	
	std::cout << "array: "; 
	printArray(array, length); 
	rearrange(array, 0, (length - 1)); 
	
	reverse(array, countNegative, (length - 1)); 
	
	std::cout << "rearranged array: "; 
	printArray(array, length); 
	return 0; 
} 
