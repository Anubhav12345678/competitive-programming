//method 1 of fibo num in log(n) except matrix exponentiation
// C++ Program to find n'th fibonacci Number in 
// with O(Log n) arithmatic operations 
#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX = 1000; 
  
// Create an array for memoization 
int f[MAX] = {0}; 
  
// Returns n'th fuibonacci number using table f[] 
int fib(int n) 
{ 
    // Base cases 
    if (n == 0) 
        return 0; 
    if (n == 1 || n == 2) 
        return (f[n] = 1); 
  
    // If fib(n) is already computed 
    if (f[n]) 
        return f[n]; 
  
    int k = (n & 1)? (n+1)/2 : n/2; 
  
    // Applyting above formula [Note value n&1 is 1 
    // if n is odd, else 0. 
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) 
           : (2*fib(k-1) + fib(k))*fib(k); 
  
    return f[n]; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int n = 9; 
    printf("%d ", fib(n)); 
    return 0; 
} 
//



//method two
// C++ Program to find n'th fibonacci Number 
// in O(n) but if we cal power in o(logn) it becomes in O(n)
#include<iostream> 
#include<cmath> 

int fib(int n) { 
double phi = (1 + sqrt(5)) / 2; 
return round(pow(phi, n) / sqrt(5)); 
} 

// Driver Code 
int main () 
{ 
int n = 9; 
std::cout << fib(n) << std::endl; 
return 0; 
} 
//This code is contributed by Lokesh Mohanty. 
#include <stdio.h> 

/* Helper function that multiplies 2 matrices F and M of size 2*2, and 
puts the multiplication result back to F[][] */
void multiply(int F[2][2], int M[2][2]); 

/* Helper function that calculates F[][] raise to the power n and puts the 
result in F[][] 
Note that this function is designed only for fib() and won't work as general 
power function */
void power(int F[2][2], int n); 

int fib(int n) 
{ 
int F[2][2] = {{1,1},{1,0}}; 
if (n == 0) 
    return 0; 
power(F, n-1); 

return F[0][0]; 
} 

void multiply(int F[2][2], int M[2][2]) 
{ 
int x = F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
int y = F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
int z = F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
int w = F[1][0]*M[0][1] + F[1][1]*M[1][1]; 

F[0][0] = x; 
F[0][1] = y; 
F[1][0] = z; 
F[1][1] = w; 
} 

void power(int F[2][2], int n) 
{ 
int i; 
int M[2][2] = {{1,1},{1,0}}; 

// n - 1 times multiply the matrix to {{1,0},{0,1}} 
for (i = 2; i <= n; i++) 
    multiply(F, M); 
} 

/* Driver program to test above function */
int main() 
{ 
int n = 9; 
printf("%d", fib(n)); 
getchar(); 
return 0; 
} 









