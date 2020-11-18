// C/C++ program to convert n into negative base form 
#include <bits/stdc++.h> 
using namespace std; 

// Utility method to convert integer into string 
string toString(int n) 
{ 
	string str; 
	stringstream ss; 
	ss << n; 
	ss >> str; 
	return str; 
} 

// Method to convert n to base negBase 
string toNegativeBase(int n, int negBase) 
{ 
	// If n is zero then in any base it will be 0 only 
	if (n == 0) 
		return "0"; 

	string converted = ""; 
	while (n != 0) 
	{ 
		// Get remainder by negative base, it can be 
		// negative also 
		int remainder = n % negBase; 
		n /= negBase; 

		// if remainder is negative, add abs(base) to 
		// it and add 1 to n 
		if (remainder < 0) 
		{ 
			remainder += (-negBase); 
			n += 1; 
		} 

		// convert remainder to string add into the result 
		converted = toString(remainder) + converted; 
	} 

	return converted; 
} 

// Driver code to test above methods 
int main() 
{ 
	int n = 13; 
	int negBase = -2; 

	cout << toNegativeBase(n, negBase); 

	return 0; 
} 
