#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to print all combinations of phrases that can be formed
// by words from each of the given lists
void printAllCombinations(auto list, int n, string res, int list_num)
{
	// if we have traversed each list
	if (list_num == n)
	{
		// print phrase after removing trailing space
		cout << res.substr(1) << endl;
		return;
	}

	// get size of current list
	int m = list[list_num].size();

	// do for each word in current list
	for (int i = 0; i < m; i++)
	{
		// append current word to output
		string out = res + " " + list[list_num].at(i);

		// recur for next list
		printAllCombinations(list, n, out, list_num + 1);
	}
}

// main function
int main()
{
	vector<string> list[] =
	{
		{ "John", "Emma" },
		{ "Plays", "Hates", "Watches" },
		{ "Cricket", "Soccer", "Chess" }
	};

	// size of the list
	int n = sizeof(list)/sizeof(list[0]);

	printAllCombinations(list, n, "", 0);

	return 0;
}