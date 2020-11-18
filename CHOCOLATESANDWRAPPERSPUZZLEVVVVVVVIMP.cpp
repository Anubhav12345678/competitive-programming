// Efficient C++ program to find maximum 
// number of chocolates 
#include <iostream> 
using namespace std; 

// Returns maximum number of chocolates we can eat 
// with given money, price of chocolate and number 
// of wrapprices required to get a chocolate. 
int countMaxChoco(int money, int price, int wrap) 
{ 
	// Corner case 
	if (money < price) 
	return 0; 

	// First find number of chocolates that 
	// can be purchased with the given amount 
	int choc = money / price; 

	// Now just add number of chocolates with the 
	// chocolates gained by wrapprices 
	choc = choc + (choc - 1) / (wrap - 1); 
	return choc; 
} 

// Driver code 
int main() 
{ 
	int money = 15 ; // total money 
	int price = 1; // cost of each candy 
	int wrap = 3 ; // no of wrappers needs to be 
	// exchanged for one chocolate. 

	cout << countMaxChoco(money, price, wrap); 
	return 0; 
} 
