#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bore(ll n)
{
    ll i,j,k,l,ans=0LL;
    string s = to_string(n);
    ll cur=1;
    for(i=1;i<s.size();i++)
    {
        cur*=5;
        ans+=cur;
    }
    for(i=1;i<=s.size();i++)
    {
        k = s[i-1]-'0';
        if(i==s.size())
        {
            if(i%2==0&&k%2==0)
            ans = ans+((k/2)+1);
            else if(i%2==1&&k%2==1)
            ans = ans+((k+1)/2);
            else
            ans = ans+((k+1)/2);
        }
        else if(i%2==1)
        {
            if(k%2==1)
            {
                ans+= ((k-1)/2)*(ll)pow(5,s.size()-i);
            }
            else
            {
                ans+= (k/2)*(ll)pow(5,s.size()-i);
            }
        }
        else if(i%2==0)
        {
            if(k%2==0)
            {
                ans+= ((k)/2)*(ll)pow(5,s.size()-i);
            }
            else
            {
                ans+= ((k+1)/2)*(ll)pow(5,s.size()-i);
            }
        }
        
        if(i%2!=k%2) break;
    }
    
    return ans;
    
}
int main() {
    
    ll  t,l,r;
    ll i;
    cin>>t;
    i=t;
    while(t--)
    {
        cin>>l>>r;
        cout<<"Case #"<<(i-t)<<": "<<bore(r)-bore(l-1)<<endl;
    }
    
    
    // your code goes here
    return 0;
}
/*
Ron read a book about boring numbers. According to the book, a positive number is called boring if all of the digits at even positions in the number are even and all of the digits at odd positions are odd. The digits are enumerated from left to right starting from 1. For example, the number 1478 is boring as the odd positions include the digits {1, 7} which are odd and even positions include the digits {4, 8} which are even.

Given two numbers L and R, Ron wants to count how many numbers in the range [L, R] (L and R inclusive) are boring. Ron is unable to solve the problem, hence he needs your help.
Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a single line with two numbers L and R.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the count of boring numbers.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1 ≤ T ≤ 100.
Test Set 1
1 ≤ L ≤ R ≤ 103.
Test Set 2
1 ≤ L ≤ R ≤ 1018.


*/