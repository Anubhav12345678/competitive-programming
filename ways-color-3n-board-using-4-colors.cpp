// C++ program to find number of ways 
// to color a 3 x n grid using 4 colors 
// such that no two adjacent have same 
// color 
#include <iostream> 
using namespace std; 

int solve(int A) 
{ 
	
	// When we to fill single column 
	long int color3 = 24; 
	long int color2 = 12; 
	long int temp = 0; 
	
	for (int i = 2; i <= A; i++) 
	{ 
		temp = color3; 
		color3 = (11 * color3 + 10 * 
			color2 ) % 1000000007; 
				
		color2 = ( 5 * temp + 7 * 
			color2 ) % 1000000007; 
	} 
	
	long num = (color3 + color2) 
					% 1000000007; 
						
	return (int)num; 
} 

// Driver code 
int main() 
{ 
	int num1 = 1; 
	cout << solve(num1) << endl; 

	int num2 = 2; 
	cout << solve(num2) << endl; 
	
	int num3 = 500; 
	cout << solve(num3) << endl; 

	int num4 = 10000; 
	cout << solve(num4); 
	
	return 0; 
} 

// This code is contributed by vt_m. 
 