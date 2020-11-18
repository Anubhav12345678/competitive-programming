#include <bits/stdc++.h>
/*

Samantha and Sam are playing a numbers game. Given a number as a string, no 
leading zeros, determine the sum of all integer values of substrings of the
 string. For example, if the string is , the substrings are  and . Their sum is .

Given an integer as a string, sum all of its substrings cast as integers. As
 the number may become large, return the value modulo .

Function Description

Complete the substrings function in the editor below. It should return the sum 
sof the integer values of all substrings in a string representation of a number, modulo .

substrings has the following parameter(s):

n: the string representation of an integer
Input Format

A single line containing an integer as a string without leading zeros.

*/
using namespace std;
#define ll long long
// Complete the substrings function below.
ll solve(string s) {
   ll i,j,k,l,n=s.size();
   ll ans=(ll)(s[0]-'0');
   ll tmp=(ll)(s[0]-'0');
   ll mod=1e9+7;
   for(i=1;i<n;i++)
   {
       tmp = tmp*10+(i+1)*(ll)(s[i]-'0');
       tmp%=mod;
       ans = (ans+tmp)%mod;
   }
   return ans;

}

int main()
{
    ll i,j,k,l,n;
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
}
