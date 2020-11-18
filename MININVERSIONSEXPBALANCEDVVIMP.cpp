#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Function to find the minimum number of inversions needed
// to make the given expression balanced
int findMinInversions(string exp, int n)
{
	// if the expression has odd length, it cannot be balanced
	if (n & 1) {
		return INT_MAX;
	}

	int inversions = 0;		// stores total inversions needed
	int open = 0;			  // stores total number of opening braces

	// traverse the expression
	for (int i = 0; i < n; i++)
	{
		// if current character is an opening brace
		if (exp[i] == '{') {
			open++;
		}

		// if current character is a closing brace
		else
		{
			// if an opening brace is found before, close it
			if (open) {
				open = open - 1;	// decrement opening brace count
			}
			else
			// invert the closing brace i.e. change '}' to '{'
			{
				inversions++;		// increment total inversions needed by 1
				open += 1;			// increment opening brace count
			}
		}
	}

	// for N opened brace, we need exactly N/2 inversions
	return inversions + open/2;
}

// main function
int main()
{
	string exp = "{{}{{}{{";
	int n = exp.length();

	int inv = findMinInversions(exp, n);

	if (inv != INT_MAX)
		cout << "Minimum number of inversions needed is " << inv;
	else
		cout << "Invalid input" << endl;

	return 0;
}