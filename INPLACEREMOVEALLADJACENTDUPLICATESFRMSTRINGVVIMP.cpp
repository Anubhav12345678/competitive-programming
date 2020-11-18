#include <iostream>
#include <string.h>
using namespace std;

// Function to in-place remove all adjacent duplicates from
// the given string
char* removeAdjDup(char* str, int n)
{
	// k maintains the index of next free location in the result
	// and i maintains the current index in the string
	int i, k = 0;
	int len = strlen(str);

	// start from second character
	for (i = 1; i < len; i++)
	{
		// if current character is not same as the
		// previous character, add it to result
		if (str[i - 1] != str[i])
			str[k++] = str[i - 1];
		else
		{
			// remove adjacent duplicates
			while (i < len && str[i - 1] == str[i])
				i++;
		}
	}
	
	// Add last character to result
	str[k++] = str[i - 1];
	
	// null terminate the string
	str[k] = '\0';

	// start again if any duplicate is removed
	if (k != n)
		return removeAdjDup(str, k); // Shlemiel Painter's Algorithm
	
	// if the algorithm didn't change the input string, that means
	// all the adjacent duplicates are removed
	return str;
}

// main function
int main()
{
	char str[] = "DBAABDAB";
	int n = strlen(str);

	cout << "The string left after removal of all adjacent duplicates is "
		 << removeAdjDup(str, n);

	return 0;
}