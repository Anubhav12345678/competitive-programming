// C++ program to determine minimum number 
// of rotations required to yield same 
// string. 
#include <iostream> 
using namespace std; 

// Returns count of rotations to get the 
// same string back. 
int findRotations(string str) 
{ 
	// tmp is the concatenated string. 
	string tmp = str + str; 
	int n = str.length(); 

	for (int i = 1; i <= n; i++) { 

		// substring from i index of original 
		// string size. 
		string substring = tmp.substr(i, str.size()); 

		// if substring matches with original string 
		// then we will come out of the loop. 
		if (str == substring) 
			return i; 
	} 
	return n; 
} 

// Driver code 
int main() 
{ 
	string str = "abc"; 
	cout << findRotations(str) << endl; 
	return 0; 
} 
