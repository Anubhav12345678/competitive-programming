#include <iostream>
#include <algorithm>
using namespace std;

// Utility function to print the subarray arr[i..j]
void printSubArray(int arr[], int i, int j)
{
	cout << "{ ";
	for (int k = i; k < j; k++) {
		cout << arr[k] << ", ";
	}
	cout << arr[j] << " }";
}

// Function to find length of longest subarray with alternating
// positive and negative elements
void findLongestSubArray(int arr[], int n)
{
	// stores length of longest alternating subarray found so far
	int max_len = 1;

	// stores ending index of longest alternating subarray found so far
	int ending_index = 0;

	// stores length of alternating subarray ending at current position
	int curr_len = 1;

	// traverse the given array starting from the second index
	for (int i = 1; i < n; i++)
	{
		// if current element has opposite sign than the previous element
		if (arr[i] * arr[i - 1] < 0)
		{
			// include current element in longest alternating subarray ending at
			// previous index
			curr_len++;

			// update result if current sub-array length is found to be greater
			if (curr_len > max_len)
			{
				max_len = curr_len;
				ending_index = i;
			}
		}
		// reset length if current element has same sign as previous element
		else {
			curr_len = 1;
		}
	}
	
	cout << "The longest alternating subarray is ";
	printSubArray(arr, (ending_index - max_len + 1), ending_index);
}

int main()
{
	int arr[] = { 1, -2, 6, 4, -3, 2, -4, -3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findLongestSubArray(arr, n);

	return 0;
}