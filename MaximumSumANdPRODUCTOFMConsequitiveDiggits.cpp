// C++ implemenattion of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the maximum product and sum 
void maxProductSum(string str, int m) 
{ 
	int n = str.length(); 
	int product = 1, sum = 0; 

	// find the sum and product of first K digits 
	for (int i = 0; i < m; i++) { 
		sum += (str[i] - '0'); 
		product *= (str[i] - '0'); 
	} 

	// Update maxProd and maxSum 
	int maxProd = product; 
	int maxSum = sum; 

	// Start traversing the next element 
	for (int i = m; i < n; i++) { 

		// Multiply with the current digit and divide by 
		// the first digit of previous window 
		product = product * (str[i] - '0') / ((str[i - m]) - '0'); 

		// Add the current digit and subtract 
		// the first digit of previous window 
		sum = sum + (str[i] - '0') - ((str[i - m]) - '0'); 

		// Update maxProd and maxSum 
		maxProd = max(maxProd, product); 
		maxSum = max(maxSum, sum); 
	} 

	cout << "Maximum Product = " << maxProd; 
	cout << "\nMaximum Sum = " << maxSum; 
} 

// Driver code 
int main() 
{ 
	string str = "3675356291"; 
	int m = 5; 

	maxProductSum(str, m); 
} 
