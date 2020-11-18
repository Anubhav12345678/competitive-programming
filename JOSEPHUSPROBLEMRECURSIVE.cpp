#include <stdio.h> 

int josephus(int n, int k) 
{ 
if (n == 1) 
	return 1; 
else
	/* The position returned by josephus(n - 1, k) is adjusted because the 
	recursive call josephus(n - 1, k) considers the original position 
	k%n + 1 as position 1 */
	return (josephus(n - 1, k) + k-1) % n + 1; 
} 

// Driver Program to test above function 
int main() 
{ 
int n = 14; 
int k = 2; 
printf("The chosen place is %d", josephus(n, k)); 
return 0; 
} 
/*
After the first person (kth from beginning) is killed, n-1 persons are left. So we call josephus(n – 1, k) to get the position
 with n-1 persons. But the position returned by josephus(n – 1, k) will consider the position starting from k%n + 1. So, 
 we must make adjustments to the position returned by josephus(n – 1, k).
*/
