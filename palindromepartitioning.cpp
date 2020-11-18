
// meeeee leetcode
class Solution {
public:
    bool ispalin(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return 0;
        }
        return 1;
    }
    int solve(string s,vector<vector<bool>> dp)
    {
        int n = s.size();
        int c[n];
        memset(c,1000000007,sizeof(c));
        for(int i=0;i<n;i++)
        {
            if(dp[0][i])
                c[i]=0;
            else
            {
                for(int j=0;j<i;j++)
                {
                    if(dp[j+1][i]&&1+c[j]<c[i])
                        c[i]=min(c[i],c[j]+1);
                }
            }
        }
        return c[n-1];
    }
    int minCut(string s) {
        int i,j,k,l,n=s.size();
        if(n==0||n==1)
            return 0;
        map<string,int> lookup;
        vector<vector<bool >> dp(n,vector<bool>(n,false));
        for(i=0;i<n;i++)
            dp[i][i]=1;
        for(l=2;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                if(l==2)
                    dp[i][j]=(s[i]==s[j]);
                else
                    dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
                // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
        }
        return solve(s,dp);
    }
};







// Dynamic Programming Solution for Palindrome Partitioning Problem 
#include <limits.h> 
#include <stdio.h> 
#include <string.h> 

// A utility function to get minimum of two integers 
int min(int a, int b) { return (a < b) ? a : b; } 

// Returns the minimum number of cuts needed to partition a string 
// such that every part is a palindrome 
int minPalPartion(char* str) 
{ 
	// Get the length of the string 
	int n = strlen(str); 

	/* Create two arrays to build the solution in bottom-up manner 
	C[i] = Minimum number of cuts needed for a palindrome partitioning 
				of substring str[0..i] 
	P[i][j] = true if substring str[i..j] is palindrome, else false 
	Note that C[i] is 0 if P[0][i] is true */
	int C[n]; 
	bool P[n][n]; 

	int i, j, k, L; // different looping variables 

	// Every substring of length 1 is a palindrome 
	for (i = 0; i < n; i++) { 
		P[i][i] = true; 
	} 

	/* L is substring length. Build the solution in bottom up manner by 
	considering all substrings of length starting from 2 to n. */
	for (L = 2; L <= n; L++) { 
		// For substring of length L, set different possible starting indexes 
		for (i = 0; i < n - L + 1; i++) { 
			j = i + L - 1; // Set ending index 

			// If L is 2, then we just need to compare two characters. Else 
			// need to check two corner characters and value of P[i+1][j-1] 
			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
		} 
	} 

	for (i = 0; i < n; i++) { 
		if (P[0][i] == true) 
			C[i] = 0; 
		else { 
			C[i] = INT_MAX; 
			for (j = 0; j < i; j++) { 
				if (P[j + 1][i] == true && 1 + C[j] < C[i]) 
					C[i] = 1 + C[j]; 
			} 
		} 
	} 

	// Return the min cut value for complete string. i.e., str[0..n-1] 
	return C[n - 1]; 
} 

// Driver program to test above function 
int main() 
{ 
	char str[] = "ababbbabbababa"; 
	printf("Min cuts needed for Palindrome Partitioning is %d", 
		minPalPartion(str)); 
	return 0; 
} 
//this below method is in O(n^2)
// Using memoizatoin to solve the partition problem. 
#include <bits/stdc++.h> 
using namespace std; 
// Function to check if input string is pallindrome or not 
bool ispallindrome(string input, int start, int end) 
{ 
	// Using two pointer technique to check pallindrome 
	while (start < end) { 
		if (input[start] != input[end]) 
			return false; 
		start++; 
		end--; 
	} 
	return true; 
} 

// Function to find keys for the Hashmap 
string convert(int a, int b) 
{ 
	return to_string(a) + "" + to_string(b); 
} 

// Returns the minimum number of cuts needed to partition a string 
// such that every part is a palindrome 
int minpalparti_memo(string input, int i, int j, unordered_map<string, int>& memo) 
{ 
	if (i > j) 
		return 0; 
	// Key for the Input String 
	string ij = convert(i, j); 

	// If the no of partitions for string "ij" is already calculated 
	// then return the calculated value using the Hashmap 
	if (memo.find(ij) != memo.end()) { 
		return memo[ij]; 
	} 
	// Every String of length 1 is a pallindrome 
	if (i == j) { 
		memo[ij] = 0; 
		return 0; 
	} 
	if (ispallindrome(input, i, j)) { 
		memo[ij] = 0; 
		return 0; 
	} 
	int minimum = INT_MAX; 
	// Make a cut at every possible location starting from i to j 
	for (int k = i; k < j; k++) { 
		int left_min = INT_MAX; 
		int right_min = INT_MAX; 
		string left = convert(i, k); 
		string right = convert(k + 1, j); 

		// If left cut is found already 
		if (memo.find(left) != memo.end()) { 
			left_min = memo[left]; 
		} 
		// If right cut is found already 
		if (memo.find(right) != memo.end()) { 
			right_min = memo[right]; 
		} 

		// Recursively calculating for left and right strings 
		if (left_min == INT_MAX) 
			left_min = minpalparti_memo(input, i, k, memo); 
		if (right_min == INT_MAX) 
			right_min = minpalparti_memo(input, k + 1, j, memo); 

		// Taking minimum of all k possible cuts 
		minimum = min(minimum, left_min + 1 + right_min); 
	} 

	memo[ij] = minimum; 
	// Return the min cut value for complete string. 
	return memo[ij]; 
} 
int main() 
{ 
	string input = "ababbbabbababa"; 
	unordered_map<string, int> memo; 
	cout << minpalparti_memo(input, 0, input.length() - 1, memo) << endl; 
	return 0; 
} 

// me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(string s)
{
	ll i,j,k,l,a,b;
	ll n = s.size();
	ll c[n][n];
	bool p[n][n];
	// memset(c,0,sizeof(c));
	// memset();
	for(i=0;i<n;i++)
	{
		c[i][i]=0;
		p[i][i]=1;
	}
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			if(l==2)
			p[i][j]=(s[i]==s[j]);
			else
			p[i][j] = (s[i]==s[j])&&p[i+1][j-1];
			if(p[i][j])
			c[i][j]=0;
			else
			{
				c[i][j]=INT_MAX;
				for(k=i;k<=j-1;k++)
				c[i][j] = min(c[i][j],c[i][k]+c[k+1][j]+1);
			}
		}
	}
	return c[0][n-1];
}
int main() {
	cout<<solve("ababbbabbababa");
	// your code goes here
	return 0;
}
//me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
bool ispalin(string s,int i,int j)
{
	if(i==j)
	return 1;
	if(j==i+1)
	return s[i]==s[j];
	int k=i,p=j;
	while(k<p)
	{
		if(s[k++]!=s[p--])
		return 0;
	}
	return 1;
}
string convert(int a,int b)
{
	return to_string(a)+""+to_string(b);
}
int solveutil(string s,int i,int j,map<string,int> &m)
{
	if(i>j)
	return 0;
	string ij = convert(i,j);
	if(m.find(ij)!=m.end())
	return m[ij];
	int k,l,h,a,b,c,leftmin=INT_MAX,rightmin=INT_MAX;
	if(i==j)
	{
		m[ij]=0;
		return 0;
	}
	if(ispalin(s,i,j))
	{
		m[ij]=0;
		return 0;
	}
	int minimum = INT_MAX;
	for(k=i;k<j;k++)
	{
		leftmin = INT_MAX;
		rightmin = INT_MAX;
		string left = convert(i,k);
		string right = convert(k+1,j);
		if(m.find(left)!=m.end())
		leftmin = m[left];
		if(m.find(right)!=m.end())
		rightmin = m[right];
		
		
		if(leftmin==INT_MAX)
		leftmin = solveutil(s,i,k,m);
		if(rightmin==INT_MAX)
		rightmin = solveutil(s,k+1,j,m);
		minimum = min(minimum,leftmin+1+rightmin);
	}
	m[ij]=minimum;
	return m[ij];
	
}
int main() {
	map<string,int> m;
	string s = "ababbbabbababa"; 
	cout<<solveutil(s,0,s.size()-1,m);
	return 0;
}	

//me
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

// define maximum length of the string
#define MAX 20

// isPalindrome[i][j] stores if substring X[i][j] is palindrome or not
bool isPalindrome[MAX][MAX];

// Bottom-up DP function to mark if string X[i..j] is a palindrome
// or not for all possible values of i and j
bool findAllPalindromes(string X, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
				isPalindrome[i][j] = true;
			else if (X[i] == X[j])
				isPalindrome[i][j] = ((j - i == 1) ? true :
									isPalindrome[i + 1][j - 1]);
			else
				isPalindrome[i][j] = false;
		}
	}
}

// Recursive function to find the minimum cuts needed in a string
// such that each partition is a palindrome
int minPalinPartition(int i, int j, auto &lookup)
{
	// base case: if starting index i and ending index j are equal
	// or X[i..j] is already a palindrome

	if (i == j || isPalindrome[i][j])
		return 0;

	// construct an unique map key from dynamic elements of the input
	// lookup[key] stores minimum number cuts needed to partition X[i..j]

	string key = to_string(i) + "|" + to_string(j);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map

	if (lookup.find(key) == lookup.end())
	{
		// take the minimum over each possible position at which the
		// string can be cut

		lookup[key] = INT_MAX;
		for (int k = i; k <= j - 1; k++)
		{
			// recur to get minimum cuts required in X[i..k] and X[k+1..j]
			int count = 1 + minPalinPartition(i, k, lookup) +
						minPalinPartition(k + 1, j, lookup);

			if (count < lookup[key])
				lookup[key] = count;
		}
	}

	// return the minimum cuts required
	return lookup[key];
}

// Find minimum cuts needed for palindromic partition of a string
int main()
{
	string X = "BABABCBADCD";
	int n = X.length();

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;

	// find all substrings of X that are palindromes
	findAllPalindromes(X, n);

	cout << "The minimum cuts required are "
		 << minPalinPartition(0, n - 1, lookup);

	return 0;
}
