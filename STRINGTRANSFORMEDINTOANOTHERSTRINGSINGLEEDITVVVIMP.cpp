#include <iostream>
#include <cstdlib>
using namespace std;

// Determine if the first string can be transformed into the
// second string with a single edit operation
bool checkEditDistance(string first, string second)
{
	// store length of both strings
	int m = first.length();
	int n = second.length();

	// difference between length of both strings is more than one
	if (abs(m - n) > 1)
		return false;

	// to keep track of number of edits
	int edits = 0;

	// i and j keep track of index of current characters in the
	// first and second string respectively

	int i = 0, j = 0;

	// loop till either string runs out
	while (i < m && j < n)
	{
		// if current character of both strings doesn't match
		if (first[i] != second[j])
		{
			// when length of the first string is more than the length
			// of the second string,
			// remove current character at index i in the first string

			if (m > n) {
				i++;
			}

			// when length of the first string is less than the length
			// of the second string, add current character at index j
			// in the second string to the first string

			else if (m < n) {
				j++;
			}

			// when length of both strings are same, replace character
			// present at index i in the first string by character
			// present at index j in the second string

			else {
				i++, j++;
			}

			// increment the number of edits
			edits++;
		}

		// if current character of both strings matches
		else {
			i++, j++;
		}
	}

	// remove any extra character left in the first string
	if (i < m) {
		edits++;
	}

	// add any extra character left in the second string to
	// the end of first string

	if (j < n) {
		edits++;
	}

	// return true if number of edits are exactly one;
	// return false otherwise

	return (edits == 1);
}

// main function
int main()
{
	cout << boolalpha;

	cout << checkEditDistance("xyz", "xz") << endl; 	// true
	cout << checkEditDistance("xyz", "xyyz") << endl;   // true
	cout << checkEditDistance("xyz", "xyx") << endl;	// true
	cout << checkEditDistance("xyz", "xxx") << endl;	// false

	return 0;
}