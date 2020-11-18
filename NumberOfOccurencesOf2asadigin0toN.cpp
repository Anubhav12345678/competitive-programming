// C++ program to count 2s from 0 to n 
#include <bits/stdc++.h> 
using namespace std; 

// Counts the number of 2s 
// in a number at d-th digit 
int count2sinRangeAtDigit(int number, int d) 
{ 
	int powerOf10 = (int)pow(10, d); 
	int nextPowerOf10 = powerOf10 * 10; 
	int right = number % powerOf10; 

	int roundDown = number - number % nextPowerOf10; 
	int roundup = roundDown + nextPowerOf10; 

	int digit = (number / powerOf10) % 10; 

	// if the digit in spot digit is 
	if (digit < 2) 
		return roundDown / 10; 

	if (digit == 2) 
		return roundDown / 10 + right + 1; 

	return roundup / 10; 
} 

// Counts the number of '2' digits between 0 and n 
int numberOf2sinRange(int number) 
{ 
	// Convert integer to String 
	// to find its length 
	stringstream convert; 
	convert << number; 
	string s = convert.str(); 
	int len = s.length(); 

	// Traverse every digit and 
	// count for every digit 
	int count = 0; 
	for (int digit = 0; digit < len; digit++) 
		count += count2sinRangeAtDigit(number, digit); 

	return count; 
} 

// Driver Code 
int main() 
{ 
	cout << numberOf2sinRange(22) << endl; 
	cout << numberOf2sinRange(100); 
	return 0; 
} 
