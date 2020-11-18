// C++ program to find pairs that can represent 
// the given number as sum of two cubes 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find pairs that can represent 
// the given number as sum of two cubes 
void findPairs(int n) 
{ 
	// find cube root of n 
	int cubeRoot = pow(n, 1.0/3.0); 

	// create an empty map 
	unordered_map<int, pair<int, int> > s; 

	// Consider all pairs such with values less 
	// than cuberoot 
	for (int x = 1; x < cubeRoot; x++) 
	{ 
		for (int y = x + 1; y <= cubeRoot; y++) 
		{ 
			// find sum of current pair (x, y) 
			int sum = x*x*x + y*y*y; 

			// do nothing if sum is not equal to 
			// given number 
			if (sum != n) 
				continue; 

			// if sum is seen before, we found two pairs 
			if (s.find(sum) != s.end()) 
			{ 
				cout << "(" << s[sum].first << ", "
					<< s[sum].second << ") and ("
					<< x << ", " << y << ")" << endl; 
			} 
			else
				// if sum is seen for the first time 
				s[sum] = make_pair(x, y); 
		} 
	} 
} 

// Driver function 
int main() 
{ 
	int n = 13832; 
	findPairs(n); 
	return 0; 
} 
