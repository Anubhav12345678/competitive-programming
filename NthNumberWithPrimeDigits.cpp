// CPP program to find n-th number with 
// prime digits 2, 3 and 7 
#include <algorithm> 
#include <iostream> 
#include <string> 
using namespace std; 

string nthprimedigitsnumber(int number) 
{ 
	int rem; 
	string num; 
	while (number) { 
		// remainder for check element position 
		rem = number % 4; 
		switch (rem) { 

		// if number is 1st position in tree 
		case 1: 
			num.push_back('2'); 
			break; 

		// if number is 2nd position in tree 
		case 2: 
			num.push_back('3'); 
			break; 

		// if number is 3rd position in tree 
		case 3: 
			num.push_back('5'); 
			break; 

		// if number is 4th position in tree 
		case 0: 
			num.push_back('7'); 
			break; 
		} 

		number = number / 4; 
	} 
	reverse(num.begin(), num.end()); 
	return num; 
} 

// Driver code 
int main() 
{ 
	int number = 21; 
	cout << nthprimedigitsnumber(10) << "\n"; 
	cout << nthprimedigitsnumber(21) << "\n"; 
	return 0; 
	a 
} 
