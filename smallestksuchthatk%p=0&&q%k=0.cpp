// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum 
// value K such that K % p = 0 
// and q % k = 0 
int getMinVal(int p, int q) 
{ 

	// If K is possible 
	if (q % p == 0) 
		return p; 

	// No such K is possible 
	return -1; 
} 

// Driver code 
int main() 
{ 
	int p = 24, q = 48; 
	cout << getMinVal(p, q); 

	return 0; 
} 
