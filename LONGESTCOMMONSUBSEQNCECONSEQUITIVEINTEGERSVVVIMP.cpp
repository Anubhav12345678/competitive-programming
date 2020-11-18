#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to find the length of largest subsequence formed by consecutive integers
int findMaxLenSubSeq(vector<int> &vec)
{
	// construct a set out of input elements
	unordered_set<int> S(vec.begin(), vec.end());

	// initialize result by 1
	int max_len = 1;

	// do for each element of the input sequence
	for (int e: vec)
	{
		// check if current element e is candidate for starting of a sequence
		// i.e. previous element (e - 1) don't exist in the set
		if (S.find(e - 1) == S.end())
		{
			// len stores the length of subsequence starting with current element
			int len = 1;

			// check for presence of elements e+1, e+2, e+3.. e+len in the set
			while (S.find(e + len) != S.end())
				len++;

			// update the result with the length of current consecutive subsequence
			max_len = max(max_len, len);
		}
	}

	// return result
	return max_len;
}

int main()
{
	vector<int> vec = { 2, 0, 6, 1, 5, 3, 7 };

	cout << "The length of maximum length consecutive subsequence is "
		 << findMaxLenSubSeq(vec);

	return 0;
}