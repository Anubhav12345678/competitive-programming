// C++ implementation of above approach 
#include <iostream> 
using namespace std; 
#define INT_SIZE 32 

int Right_most_setbit(int num) 
{ 
	int pos = 1; 
	// counting the position of first set bit 
	for (int i = 0; i < INT_SIZE; i++) { 
		if (!(num & (1 << i))) 
			pos++; 
		else
			break; 
	} 
	return pos; 
} 
int main() 
{ 
	int num = 18; 
	int pos = Right_most_setbit(num); 
	cout << pos << endl; 
	return 0; 
} 
// new
// C++ program for Position 
// of rightmost set bit 
#include <iostream> 
#include <math.h> 
using namespace std; 

class gfg 
{ 

public: 
unsigned int getFirstSetBitPos(int n) 
{ 
	return log2(n & -n) + 1; 
} 
}; 

// Driver code 
int main() 
{ 
	gfg g; 
	int n = 12; 
	cout << g.getFirstSetBitPos(n); 
	return 0; 
} 

// This code is contributed by SoM15242 

// This approach has been contributed by @vivek kumar9 
