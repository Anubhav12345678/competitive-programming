// C++ program find all the possible combinations of 
// k-bit numbers with n-bits set where 1 <= n <= k 
#include <iostream> 
#include <vector> 
using namespace std; 
// maximum allowed value of K 
#define K 16 

// DP lookup table 
vector<string> DP[K][K]; 

// Function to find all combinations k-bit numbers with 
// n-bits set where 1 <= n <= k 
void findBitCombinations(int k) 
{ 
	string str = ""; 
	
	// DP[k][0] will store all k-bit numbers 
	// with 0 bits set (All bits are 0's) 
	for (int len = 0; len <= k; len++) 
	{ 
		DP[len][0].push_back(str); 
		str = str + "0"; 
	} 
	
	// fill DP lookup table in bottom-up manner 
	// DP[k][n] will store all k-bit numbers 
	// with n-bits set 
	for (int len = 1; len <= k; len++) 
	{ 
		for (int n = 1; n <= len; n++) 
		{ 
			// prefix 0 to all combinations of length len-1 
			// with n ones 
			for (string str : DP[len - 1][n]) 
				DP[len][n].push_back("0" + str); 

			// prefix 1 to all combinations of length len-1 
			// with n-1 ones 
			for (string str : DP[len - 1][n - 1]) 
				DP[len][n].push_back("1" + str); 
		} 
	} 
	
	// print all k-bit binary strings with 
	// n-bit set 
	for (int n = 1; n <= k; n++) 
	{ 
		for (string str : DP[k][n]) 
			cout << str << " "; 

		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	int k = 5; 
	findBitCombinations(k); 

	return 0; 
} 
