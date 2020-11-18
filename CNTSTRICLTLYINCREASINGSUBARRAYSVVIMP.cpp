#include <iostream>
using namespace std;

// Function to count the number of strictly increasing sub-arrays in an array
int getCount(int arr[], int n)
{
	// stores the count of strictly increasing sub-arrays
	int count = 0;

	// stores the length of current strictly increasing sub-array
	int len = 1;

	// traverse the array from left to right starting from the 1st index
	for (int i = 1; i < n; i++)
	{
		// if previous element is less than the current element
		if (arr[i - 1] < arr[i])
		{
			// add the length of current strictly increasing sub-array
			// to the answer and increment it
			count += (len++);
		}
		else
		{
			// reset the length to 1
			len = 1;
		}
	}

	// return the count of strictly increasing sub-arrays
	return count;
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 4, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "The number of strictly increasing sub-arrays are "
		 << getCount(arr, n);

	return 0;
}