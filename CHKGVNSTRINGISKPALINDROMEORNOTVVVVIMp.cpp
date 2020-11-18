#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if the given string is K-Palindrome or not
bool isKPalindrome(string X, int K)
{
	// Y is reverse of X
	string Y = X;
	reverse(Y.begin(), Y.end());

	int m = X.length();
	int n = m;

	// lookup table to store solution of already computed sub-problems
	int T[m + 1][n + 1];

	// fill the lookup table T[][] in bottom-up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// if either string is empty, remove all characters from
			// other string
			if (i == 0 || j == 0)
				T[i][j] = i + j;

			// ignore last characters of both strings if they are same
			// and process remaining characters
			else if (X[i - 1] == Y[j - 1])
				T[i][j] = T[i - 1][j - 1];

			// if last character of both strings is different, consider
			// minimum by removing last character from the X and Y
			else
				T[i][j] = 1 + min(T[i - 1][j], T[i][j - 1]);
		}
	}

	return (T[m][n] <= 2 * K);
}

// main function
int main()
{
	string str = "CABCBC";
	int K = 2;

	if (isKPalindrome(str, K))
		cout << "String is K-Palindrome";
	else
		cout << "String is not a K-Palindrome";

	return 0;
}