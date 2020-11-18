// C++ program to find maximum and minimum 
// possible sums of two numbers that we can 
// get if replacing digit from 5 to 6 and vice 
// versa are allowed. 
#include<bits/stdc++.h> 
using namespace std; 

// Find new value of x after replacing digit 
// "from" to "to" 
int replaceDig(int x, int from, int to) 
{ 
	int result = 0; 
	int multiply = 1; 

	while (x % 10 > 0) 
	{ 
		int reminder = x % 10; 

		// Required digit found, replace it 
		if (reminder == from) 
			result = result + to * multiply; 

		else
			result = result + reminder * multiply; 

		multiply *= 10; 
		x = x / 10; 
	} 
	return result; 
} 

// Returns maximum and minimum possible sums of 
// x1 and x2 if digit replacements are allowed. 
void calculateMinMaxSum(int x1, int x2) 
{ 
	// We always get minimum sum if we replace 
	// 6 with 5. 
	int minSum = replaceDig(x1, 6, 5) + 
				replaceDig(x2, 6, 5); 

	// We always get maximum sum if we replace 
	// 5 with 6. 
	int maxSum = replaceDig(x1, 5, 6) + 
				replaceDig(x2, 5, 6); 
	cout << "Minimum sum = " << minSum; 
	cout << "nMaximum sum = " << maxSum; 
} 

// Driver code 
int main() 
{ 
	int x1 = 5466, x2 = 4555; 
	calculateMinMaxSum(x1, x2); 
	return 0; 
} 
