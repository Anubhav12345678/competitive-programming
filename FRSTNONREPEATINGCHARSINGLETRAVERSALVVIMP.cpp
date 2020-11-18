#include <iostream>
#include <unordered_map>
using namespace std;

// Function to find the first non-repeating character in
// the string by doing only one traversal of it
int nonRepeatingChar(string str, int n)
{
	// map to store character count and the index of its
	// last occurrence in the string
	unordered_map<char, pair<int, int>> map;

	for(int i = 0 ; i < n; i++)
	{
		map[str[i]].first++;
		map[str[i]].second = i;
	}

	// stores index of first non-repeating character
	int min_index = n;
	
	// traverse map and find character having count 1 and
	// having minimum index in the string
	for (auto it : map)
	{
		int count = it.second.first;
		int firstIndex = it.second.second;

		if (count == 1 && firstIndex < min_index)
			min_index = firstIndex;
	}
	
	return min_index;
}

int main()
{
	string str = "ABCDBAGHC";
	int n = str.length();

	int index = nonRepeatingChar(str, n);
	if (index != n)
		cout << "The first non-repeating character in the string is "
			 << str[index];
	
	return 0;
}