#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common prefix between two strings
string LCP(string X, string Y)
{
	int i = 0, j = 0;
	while (i < X.length() && j < Y.length())
	{
		if (X[i] != Y[j])
			break;

		i++, j++;
	}

	return X.substr(0, i);
}

// A recursive function to find the longest common prefix (LCP) between
// given set of strings
string findLCP(vector<string> const &words, int low, int high)
{
	// base case: if low is more than high index, return an empty string
	if (low > high)
		return string("");

	// base case: if low is equal to high, return the current string
	if (low == high)
		return words[low];

	// find the mid index
	int mid = (low + high) / 2;

	// partition the problem into sub-problems and recur for each sub-problem
	string X = findLCP(words, low, mid);
	string Y = findLCP(words, mid + 1, high);

	// return the longest common prefix of strings X and Y
	return LCP(X, Y);
}

// main function
int main()
{
	vector<string> words { "techie delight", "tech", "techie",
						   "technology", "technical" };

	cout << "The longest common prefix is "
		 << findLCP(words, 0, words.size() - 1);

	return 0;
}