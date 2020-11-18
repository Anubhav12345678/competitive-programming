// C++ program to count number of ways to express 
// N as sum of consecutive numbers. 
#include <bits/stdc++.h> 
using namespace std; 

long int countConsecutive(long int N) 
{ 
	// constraint on values of L gives us the 
	// time Complexity as O(N^0.5) 
	long int count = 0; 
	for (long int L = 1; L * (L + 1) < 2 * N; L++) 
	{ 
		float a = (1.0 * N-(L * (L + 1)) / 2) / (L + 1); 
		if (a-(int)a == 0.0) 
			count++;		 
	} 
	return count; 
} 

// Driver Code 
int main() 
{ 
	long int N = 15; 
	cout << countConsecutive(N) << endl; 
	N = 10; 
	cout << countConsecutive(N) << endl; 
	return 0; 
} 

//mee leetcode

/*
The thought process goes like this- Given a number N, we can possibly write it as a sum of 2 numbers, 3 numbers,
 4 numbers and so on. Let's assume the fist number in this series be x. Hence, we should have
x + (x+1) + (x+2)+...+ k terms = N
kx + k*(k-1)/2 = N implies
kx = N - k*(k-1)/2
So, we can calculate the RHS for every value of k and if it is a multiple of k then we can construct a sum of N 
using k terms starting from x.
Now, the question arises, till what value of k should we loop for? That's easy. In the worst case, RHS should be
 greater than 0. That is
N - k*(k-1)/2 > 0 which implies
k*(k-1) < 2N which can be approximated to
k*k < 2N ==> k < sqrt(2N)
Hence the overall complexity of the algorithm is O(sqrt(N))

PS: OJ expects the answer to be 1 greater than the number of possible ways because it considers N as being written
 as N itself. It's confusing since they ask for sum of consecutive integers which implies atleast 2 numbers. But to 
 please OJ, we should start count from 1.

*/
#define ll long long
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        ll i,j,k,l,m;
        ll cnt=1;
        for(k=2;k<sqrt(2*N);k++){
            if((N-((k*(k-1))/2))%k==0) cnt++;
        }
        return cnt;
    }
};
