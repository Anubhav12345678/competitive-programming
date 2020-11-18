// C++ program for Babylonian 
// method for square root 
#include <iostream> 
using namespace std; 

class gfg { 

	/*Returns the square root of n. 
Note that the function */
public: 
	float squareRoot(float n) 
	{ 
		/*We are using n itself as initial approximation 
	This can definitely be improved */
		float x = n; 
		float y = 1; 

		/* e decides the accuracy level*/
		float e = 0.000001; 
		while (x - y > e) { 
			x = (x + y) / 2; 
			y = n / x; 
		} 
		return x; 
	} 
}; 

/* Driver code*/
int main() 
{ 
	gfg g; 
	int n = 49; 
	cout << "Square root of " << n << " is " << g.squareRoot(n); 
	getchar(); 
} 

// This code is contributed by SoM15242 
