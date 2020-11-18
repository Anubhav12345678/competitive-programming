// c++ code to count the frequency of 1 
// in numbers less than or equal to 
// the given number. 
//Given an integer n, count the total number of digit 1 appearing in all positive integers less than or equal to n.
#include <bits/stdc++.h> 
using namespace std; 

// function to count the frequency of 1. 
int countDigitOne(int n) 
{ 
	int countr = 0; 
	for (int i = 1; i <= n; i *= 10) { 
		int divider = i * 10; 
		countr += (n / divider) * i + 
			min(max(n % divider - i + 1, 0), i); 
	} 
	return countr; 
} 

// driver function 
int main() 
{ 
	int n = 13; 
	cout << countDigitOne(n) << endl; 
	n = 113; 
	cout << countDigitOne(n) << endl; 
	n = 205; 
	cout << countDigitOne(n) << endl; 
} 
