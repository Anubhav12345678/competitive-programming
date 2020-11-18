#include <iostream>
#include <string>
using namespace std;

// Recursive function to calculate factorial of a number
int factorial(int n)
{
	return (n <= 2) ? n : n * factorial(n - 1);
}

// Function to find Lexicographic rank of a string
int findLexicographicRank(string str, int n)
{
	// rank starts from 1
	int rank = 1;

	for (int i = 0; i < n; i++)
	{
		// count all smaller characters than str[i] to the right of i
		int count = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (str[i] > str[j])
				count++;
		}
		// add current count to the rank
		rank += count * factorial(n - i);
	}

	return rank;
}

// Find Lexicographic rank of a string
int main()
{
	string str = "DCBA";
	int n = str.length();

	cout << "Lexicographic Rank of " << str << " is "
			<< findLexicographicRank(str, n - 1);

	return 0;
}


//INTERVIEWBIT
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod  = 1000003;
ll fact(ll n) { return (n<=1)?1:(n*fact(n-1))%mod; }
int Solution::findRank(string s) {
    ll i,j,k,l,n=s.size();
    ll c=0,ans=0LL;
    for(i=0;i<n;i++){
        c=0;
        for(j=i+1;j<n;j++){
            if(s[j]<s[i])
            c++;
        }
        ans = (ans+c*fact(n-i-1))%mod;
    }
    return (ans+1)%mod;
}
