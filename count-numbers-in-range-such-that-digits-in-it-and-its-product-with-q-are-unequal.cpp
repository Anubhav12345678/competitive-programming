// C++ program to count numbers in the range [l, r] 
// such that all of the digits of the number and 
// it's product with q are unequal 

#include <bits/stdc++.h> 
using namespace std; 

// Function to check if all of the digits 
// in a number and it's product with q 
// are unequal or not 
bool checkIfUnequal(int n, int q) 
{ 
	// convert first number into string 
	string s1 = to_string(n); 
	int a[26] = { 0 }; 

	// Insert elements from 1st number 
	// to hash 
	for (int i = 0; i < s1.size(); i++) 
		a[s1[i] - '0']++; 

	// Calculate corresponding product 
	int prod = n * q; 

	// Convert the product to string 
	string s2 = to_string(prod); 

	// Using the hash check if any digit of 
	// product matches with the digits of 
	// input number 
	for (int i = 0; i < s2.size(); i++) 
		if (a[s2[i] - '0']) // if yes, return false 
			return false; 

	// else, return true 
	return true; 
} 

// Function to count numbers in the range [l, r] 
// such that all of the digits of the number and 
// it's product with q are unequal 
int countInRange(int l, int r, int q) 
{ 
	int count = 0; 

	for (int i = l; i <= r; i++) { 
		// check for every number between l and r 
		if (checkIfUnequal(i, q)) 
			count++; 
	} 

	return count; 
} 

// Driver Code 
int main() 
{ 

	int l = 10, r = 12, q = 2; 

	cout << countInRange(l, r, q); 

	return 0; 
} 
