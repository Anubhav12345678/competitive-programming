// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the greatest divisor that 
// divides all the natural numbers in the range [l, r] 
int find_greatest_divisor(int l, int r) 
{ 
	if (l == r) 
		return l; 

	return 1; 
} 

// Driver Code 
int main() 
{ 
	int l = 2, r = 12; 

	cout << find_greatest_divisor(l, r); 
} 
