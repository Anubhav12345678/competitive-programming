#include <iostream>
#include <string>
using namespace std;

// define max number of elements in array
#define N 10

// lookup table to store solutions of subproblem
// max(lookup[i][0], lookup[i][1]) stores longest sequence
// till arr[0..i]
int lookup[N][2];

// Util function to find length of longest alternating subsequence
// if flag is true, next element should be greater
// if flag is false, next element should be smaller
int Util(int arr[], int start, int end, bool flag)
{
	// if sub-problem is seen for the first time, solve it and
	// store its result in lookup table
	if (lookup[start][flag] == 0)
	{
		int res = 0;
		for (int i = start; i <= end; i++)
		{
			// include arr[i] as next high in subsequence and flip flag
			// for next subsequence
			if (flag && arr[i - 1] < arr[i])
				res = max(res, 1 + Util(arr, i + 1, end, !flag));

			// include arr[i] as next low in subsequence and flip flag
			// for next subsequence
			else if (!flag && arr[i - 1] > arr[i])
				res = max(res, 1 + Util(arr, i + 1, end, !flag));

			// don't include arr[i] in subsequence
			else
				res = max(res, Util(arr, i + 1, end, flag));
		}

		lookup[start][flag] = res;
	}

	// return solution to current sub-problem
	return lookup[start][flag];
}

// Function to find length of longest subsequence with alternate
// low and high elements. It uses Util() method.
int findLongestSequence(int arr[], int n)
{
	// Fix first element and recur for remaining elements.
	// There are two possibilities -

	// 1. Next element is greater (pass true)
	// 2. Next element is smaller (pass false)
	return 1 + max(Util(arr, 1, n - 1, true),
				Util(arr, 1, n - 1, false));
}

// main function
int main()
{
	int arr[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Find Longest alternating subsequence
	cout << "The length of Longest Subsequence is "
			<< findLongestSequence(arr, n);

	return 0;
}