// C++ proggram to find count of sub-arrays 
// with odd sum 
#include <bits/stdc++.h> 
using namespace std; 

int countOddSum(int ar[], int n) 
{ 
	// A temporary array of size 2. temp[0] is 
	// going to store count of even subarrays 
	// and temp[1] count of odd. 
	// temp[0] is initialized as 1 because there 
	// a single odd element is also counted as 
	// a subarray 
	int temp[2] = { 1, 0 }; 

	// Initialize count. sum is sum of elements 
	// under modulo 2 and ending with arr[i]. 
	int result = 0, val = 0; 

	// i'th iteration computes sum of arr[0..i] 
	// under modulo 2 and increments even/odd count 
	// according to sum's value 
	for (int i = 0; i <= n - 1; i++) { 
		// 2 is added to handle negative numbers 
		val = ((val + ar[i]) % 2 + 2) % 2; 

		// Increment even/odd count 
		temp[val]++; 
	} 

	// An odd can be formed by even-odd pair 
	result = (temp[0] * temp[1]); 

	return (result); 
} 
// another approach
// Driver code 
int main() 
{ 
	int ar[] = { 5, 4, 4, 5, 1, 3 }; 
	int n = sizeof(ar) / sizeof(ar[0]); 

	cout << "The Number of Subarrays with odd"
			" sum is "
		<< countOddSum(ar, n); 

	return (0); 
} 





// CPP program to find number of subarrays with odd sum 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find number of subarrays with odd sum 
int countOddSum(int a[], int n) 
{ 
	// 'odd' stores number of odd numbers upto ith index 
	// 'c_odd' stores number of odd sum subarrays starting at ith index 
	// 'Result' stores the number of odd sum subarrays 
	int odd = 0, c_odd=0, result = 0; 
	
	// First find number of odd sum subarrays starting at 0th index 
	for(int i=0;i <n;i++) { 
		if(a[i]&1) { 
			odd = !odd; 
		} 
		if(odd) { 
			c_odd++; 
		} 
	} 

	// Find number of odd sum subarrays starting at ith index 
	// add to result 
	for(int i=0; i<n; i++) { 
		result += c_odd; 
		if(a[i]&1) { 
			c_odd = (n-i-c_odd); 
		} 
	} 
	
	return result; 
} 

// Driver code 
int main() 
{ 
	int ar[] = { 5, 4, 4, 5, 1, 3 }; 
	int n = sizeof(ar) / sizeof(ar[0]); 

	cout << "The Number of Subarrays with odd sum is "
		<< countOddSum(ar, n); 

	return (0); 
} 

