/*Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.

Example 1
Following are all the 3 possible ways to fill up a 3 x 2 board.


Example 2
Here is one possible way of filling a 3 x 8 board. You have to find all the possible ways to do so.

Examples :

Input : 2
Output : 3

Input : 8
Output : 153

Input : 12
Output : 2131
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Defining Subproblems:
At any point while filling the board, there are three possible states that the last column can be in:


An =  No. of ways to completely fill a 3 x n board. (We need to find this)
Bn =  No. of ways to fill a 3 x n board with top corner in last column not filled.
Cn =  No. of ways to fill a 3 x n board with bottom corner in last column not filled.
Note: The following states are impossible to reach:




Finding Reccurences
Note: Even though Bn and Cn are different states, they will be equal for same ‘n’. i.e Bn = Cn
Hence, we only need to calculate one of them.



Calculating An:

 A_{n} = A_{n-2} + B_{n-1} + C_{n-1}  
 A_{n} = A_{n-2} + 2*(B_{n-1}) 



Calculating Bn:

 B_{n} = A_{n-1} + B_{n-2} 



Final Recursive Relations are:

 A_{n} = A_{n-2} + 2*(B_{n-1}) 
 B_{n} = A_{n-1} + B_{n-2} 
Base Cases:

 A_0 = 1  A_1 = 0   B_0 = 0 B_1 = 1 

*/
// C++ program to find no. of ways 
// to fill a 3xn board with 2x1 dominoes. 
#include <iostream> 
using namespace std; 
  
int countWays(int n) 
{ 
    int A[n + 1], B[n + 1]; 
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1; 
    for (int i = 2; i <= n; i++) { 
        A[i] = A[i - 2] + 2 * B[i - 1]; 
        B[i] = A[i - 1] + B[i - 2]; 
    } 
  
    return A[n]; 
} 
  
int main() 
{ 
    int n = 8; 
    cout << countWays(n); 
    return 0; 
} 