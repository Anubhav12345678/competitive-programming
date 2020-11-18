#include <stdio.h>

// Function to find all N-digit numbers with sum of digits equal
// to sum in Bottom-up manner
void findNdigitNums(char res[], int index, int n, int sum)
{
	// if number is less than N-digit and its sum of digits is
	// less than the given sum
	if (index < n && sum >= 0)
	{
		char d = '0';

		// special case - number can't start from 0
		if (index == 0) {
			d = '1';
		}
	
		// consider every valid digit and put it in the current
		// index and recur for next index
		while (d <= '9')
		{
			res[index] = d;
			int digit = (d - '0');
			findNdigitNums(res, index + 1, n, sum - digit);
			d++;
		}
	}

	// if number becomes N-digit and its sum of digits is
	// equal to given sum, print it
	else if (index == n && sum == 0) {
		printf("%s ", res);
	}
}

// main function
int main()
{
	int n = 3;		// N-digit
	int sum = 6;	// given sum

	// character array to store result
	char res[n + 1];
	res[n] = '\0';		// null terminate the array

	findNdigitNums(res, 0, n, sum);

	return 0;
}