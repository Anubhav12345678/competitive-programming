#include <bits/stdc++.h>
using namespace std;
#define ll uint64_t
/*
You are given a board of size n×n, where n is odd (not divisible by 2).
 Initially, each cell of the board contains one figure.

In one move, you can select exactly one figure presented in some cell and 
move it to one of the cells sharing a side or a corner with the current cell,
 i.e. from the cell (i,j) you can move the figure to cells:

(i−1,j−1);
(i−1,j);
(i−1,j+1);
(i,j−1);
(i,j+1);
(i+1,j−1);
(i+1,j);
(i+1,j+1);
Of course, you can not move figures to cells out of the board. It is allowed that
 after a move there will be several figures in one cell.

Your task is to find the minimum number of moves needed to get all the figures into 
one cell (i.e. n2−1 cells should contain 0 figures and one cell should contain n2 figures).

You have to answer t independent test cases.


*/
ll solve(ll n)
{
	/*
	
	It is intuitive (and provable) that the best strategy is to move
	each figure to the center cell (n+12,n+12). Now, with some paperwork 
	or easy observations, we can notice that we have exactly 8 cells with
	the shortest distance 1, 16 cells with the shortest distance 2, 24 cells
	with the shortest distance 3 and so on. So we have 8i cells with the 
	shortest distance i. So the answer is 1⋅8+2⋅16+3⋅24+⋯+(n−12)2⋅8
	. It can be rewritten as 8(1+4+9+⋯+(n−12)2) so we can just calculate 
	the sum of squares of all integers from 1 to n−12 using loop
	(or formula n(n+1)(2n+1)6) and multiply the answer by 8.

Time complexity: O(n) or O(1).
	
	
	*/
	return ((n*(n*n-1))/24)*8;
	// cout<<dp[n]<<endl;
}
int main() {
	ll i,j,k,l,n,t;
	// solve();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	
	// your code goes here
	return 0;
}