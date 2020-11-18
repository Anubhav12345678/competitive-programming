// A dynamic programming solution for longest palindr. 
// This code is adopted from following link 
// http://www.leetcode.com/2011/11/longest-palindromic-substring-part-i.html 

#include <stdio.h> 
#include <string.h> 

// A utility function to print a substring str[low..high] 
void printSubStr( char* str, int low, int high ) 
{ 
	for( int i = low; i <= high; ++i ) 
		printf("%c", str[i]); 
} 

// This function prints the longest palindrome substring 
// of str[]. 
// It also returns the length of the longest palindrome 
int longestPalSubstr( char *str ) 
{ 
	int n = strlen( str ); // get length of input string 

	// table[i][j] will be false if substring str[i..j] 
	// is not palindrome. 
	// Else table[i][j] will be true 
	bool table[n][n]; 
	memset(table, 0, sizeof(table)); 

	// All substrings of length 1 are palindromes 
	int maxLength = 1; 
	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	// check for sub-string of length 2. 
	int start = 0; 
	for (int i = 0; i < n-1; ++i) 
	{ 
		if (str[i] == str[i+1]) 
		{ 
			table[i][i+1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	// Check for lengths greater than 2. k is length 
	// of substring 
	for (int k = 3; k <= n; ++k) 
	{ 
		// Fix the starting index 
		for (int i = 0; i < n-k+1 ; ++i) 
		{ 
			// Get the ending index of substring from 
			// starting index i and length k 
			int j = i + k - 1; 

			// checking for sub-string from ith index to 
			// jth index iff str[i+1] to str[j-1] is a 
			// palindrome 
			if (table[i+1][j-1] && str[i] == str[j]) 
			{ 
				table[i][j] = true; 

				if (k > maxLength) 
				{ 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

	printf("Longest palindrome substring is: "); 
	printSubStr( str, start, start + maxLength - 1 ); 

	return maxLength; // return length of LPS 
} 

// Driver program to test above functions 
int main() 
{ 
	char str[] = "forgeeksskeegfor"; 
	printf("\nLength is: %d\n", longestPalSubstr( str ) ); 
	return 0; 
} 

// ANOTHER APPROACH INTERVIEW BIT
string expandAroundCenter(string s, int c1, int c2) {
            int l = c1, r = c2;
            int n = s.length();
            while (l >= 0 && r <= n-1 && s[l] == s[r]) {
                l--;
                r++;
            }
            return s.substr(l+1, r-l-1);
        }
string Solution::longestPalindrome(string A) {
     int n = A.length();
            if (n == 0) return "";
            string longest = A.substr(0, 1);  // a single char itself is a palindrome
            for (int i = 0; i < n-1; i++) {
                string p1 = expandAroundCenter(A, i, i);
                if (p1.length() > longest.length())
                    longest = p1;

                string p2 = expandAroundCenter(A, i, i+1);
                if (p2.length() > longest.length())
                    longest = p2;
            }
            return longest;
    // string org = A;
    // reverse(A.begin(),A.end());
    
}

// another appraoch to find longest palibdromic substring length
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lcs(string a,string b) // longest common subsequence
{
	int m = a.size();
	int n = b.size();
	int i,j,k,l;
    int t[m+1][n+1];
    for(i=0;i<=m;i++)
    {
    	for(j=0;j<=n;j++)
    	{
    		if(i==0||j==0)
    			t[i][j]=0;
    		else if(a[i-1]==b[j-1])
    			t[i][j] = 1+t[i-1][j-1];
    		else
    			t[i][j] = max(t[i-1][j],t[i][j-1]);
    	}
    }
    return t[m][n];
}
int main()
{
	int i,j,k,l;
	string a,b;
	cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    cout<<"length of longest palibdromic subsequence is "<<lcs(a,b)<<endl;
}