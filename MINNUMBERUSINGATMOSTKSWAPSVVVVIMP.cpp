#include <iostream>
#include <algorithm>
using namespace std;

// Find minimum number formed by doing at-most k swap operations upon
// digits of string
void findMin(string S, int n, int k, string &min_so_far)
{
	// compare current number with minimum number so far
	if (min_so_far.compare(S) > 0)
		min_so_far = S;

	// base case: no swaps left
	if (k < 1)
		return;

	// do for each digit in the input string
	for (int i = 0; i < n - 1; i++)
	{
		// compare the current digit with remaining digits
		for (int j = i + 1; j < n; j++)
		{
			// if digit at i'th index is more than the digit at j'th index
			if (S[i] > S[j])
			{
				// swap S[i] and S[j]
				swap(S[i], S[j]);

				// recur for remaining k - 1 swaps
				findMin(S, n, k - 1, min_so_far);

				// backtrack - restore the string back
				swap(S[i], S[j]);
			}
		}
	}
}

int main()
{
	// input string and number
	string S = "934651";
	int k = 2;

	string minimum = S;
	findMin(S, S.length(), k, minimum);

	cout << "The minimum number formed by doing at-most " << k 
		 << " swaps is " << minimum;

	return 0;
}