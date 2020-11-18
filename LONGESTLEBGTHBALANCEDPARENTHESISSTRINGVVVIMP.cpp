#include <iostream>
#include <stack>
using namespace std;

// Function to find length of the longest balanced parenthesis in a string
int findMaxLen(string str)
{
	// create a stack of integers for storing index of parenthesis in the string
	stack<int> stack;

	// initialize the stack by -1
	stack.push(-1);

	// stores the length of the longest balanced parenthesis
	int len = 0;

	// iterate over characters of the string
	for (int i = 0; i < str.length(); i++)
	{
		// if current character is an opening parenthesis,
		// push its index in the stack
		if (str[i] == '(') {
			stack.push(i);
		}

		// if current character is a closing parenthesis
		else
		{
			// pop top index from the stack
			stack.pop();

			// if the stack becomes empty, push current index into the stack
			if (stack.empty())
			{
				stack.push(i);
				continue;
			}

			// get length of the longest balanced parenthesis ending
			// at current character
			int curr_len = i - stack.top();

			// update length of longest balanced parenthesis if required
			if (len < curr_len)
			   len = curr_len;
		}
	}
	
	return len;
}

int main()
{
	cout << findMaxLen("((()()") << endl;	 // prints 4
	cout << findMaxLen("(((()") << endl;	  // prints 2
	cout << findMaxLen("((((") << endl;	   // prints 0
	cout << findMaxLen("()()") << endl;	   // prints 4
	cout << findMaxLen("(()())(()");		  // prints 6

	return 0;
}