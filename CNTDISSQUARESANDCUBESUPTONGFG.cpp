// C++ implementation of above approach 
#include <iostream> 
#include <math.h> // For sqrt() and cbrt() 
using namespace std; 

// Function to count the number 
// of perfect squares and cubes 
int countSC(int N) 
{ 
	int res = (int)sqrt(N) + (int)cbrt(N) 
			- (int)(sqrt(cbrt(N))); 

	return res; 
} 

// Driver code 
int main() 
{ 
	int N = 20; 

	cout << "Number of squares and cubes is " << countSC(N); 
	return 0; 
} 
