#include <iostream>
#include <unordered_map>
using namespace std;

// Construct the longest palindrome by shuffling or deleting
// characters from a given string
string longestPalindrome(string const &str)
{
	// create a frequency map for characters of given string
	unordered_map<char, int> freq;
	for (char ch: str) {
		freq[ch]++;
	}

	char mid_char;	  // stores odd character
	string left;		// stores left substring

	// iterate through the frequency map
	for (auto p: freq)
	{
		char ch = p.first;		// get current character
		int count = p.second;	 // get character frequency

		// if the frequency of current character is odd
		// update mid to current char (and discard old one)
		if (count & 1) {
			mid_char = ch;
		}

		// append half of the characters to the left substring
		// (other half goes to the right substring in reverse order)
		left.append(count/2, ch);
	}

	// right substring will be reverse of left substring
	string right(left.rbegin(), left.rend());

	// return string formed by the left substring, mid character (if any)
	// and the right substring
	return (left + mid_char + right);
}

// main function
int main()
{
	string str = "ABBDAB";

	cout << "The Longest Palindrome is " << longestPalindrome(str);

	return 0;
}