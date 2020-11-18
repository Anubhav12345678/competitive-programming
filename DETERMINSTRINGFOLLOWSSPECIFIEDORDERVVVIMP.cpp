#include <iostream>
#include <string>
using namespace std;
// The idea is to loop through all the characters of the pattern and if at any instant
// the last ocurence of previous encountered character is after the first occurence of current character we return false.
// Determine if characters of a given string follows specific order as
// defined by characters of the given pattern
bool checkPattern(string s, string pattern)
{
	// invalid input
	if (s.length() < pattern.length())
		return false;

	// stores previous seen character (initially NUL)
	char prev = '\0';

	// loop through all chars of the pattern
	for (char curr: pattern)
	{
		// return false if last occurrence of previous character is after
		// the first occurrence of current character in the input string
		if (prev != '\0' && s.find_last_of(prev) > s.find_first_of(curr))
			return false;

		// set current char as previous char for next iteration
		prev = curr;
	}

	// we reach here if the given string matches the pattern
	return true;
}

// main function
int main()
{
	string s = "Techie Delight";
	string pattern = "el";

	if (checkPattern(s, pattern))
		cout << "Pattern found";
	else
		cout << "Pattern not found";

	return 0;
}