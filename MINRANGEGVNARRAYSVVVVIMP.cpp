#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to find the minimum range with at-least one element from
// each of the given arrays
auto findMinRange(auto &a, auto &b, auto &c)
{
	// create a pair to store the result
	pair<int, int> pair;

	// stores the minimum difference
	int diff = numeric_limits<int>::max();

	// a triplet is formed by (a[i], b[j], c[k])
	int i = 0, j = 0, k = 0;
	
	// loop till the end of any array is reached
	while (i < a.size() && j < b.size() && k < c.size())
	{
		// find minimum and maximum value in current triplet
		int low = min(min(a[i], b[j]), c[k]);
		int high = max(max(a[i], b[j]), c[k]);

		// update the minimum difference if current difference is more
		// and store the elements in a pair
		if (diff > high - low)
		{
			pair = make_pair(low, high);
			diff = high - low;
		}

		// advance index of the array with minimum value
		if (a[i] == low) {
			i++;
		}
		else if (b[j] == low) {
			j++;
		}
		else {
			k++;
		}
	}

	return pair;
}

int main()
{
	vector<int> a = { 2, 3, 4, 8, 10, 15 };
	vector<int> b = { 1, 5, 12 };
	vector<int> c = { 7, 8, 15, 16 };

	auto pair = findMinRange(a, b, c);
	cout << "Minimum Range is [" << pair.first << ", " << pair.second << "]";

	return 0;
}