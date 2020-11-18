#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll N){
    ll cnt=0LL;
    for(ll L=1;(L*(L+1))<2*N;L++){
        double a =  (double)(1.0*N-((L*(L+1))/2))/(L+1);
        if(a-(ll)a==0) cnt++;
    }
    return cnt;
}
int main() {
    ll n;
    cin>>n;
    cout<<solve(n)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
/*
Given a number N, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:

Input :15 
Output :3
15 can be represented as:
1+2+3+4+5
4+5+6
7+8

Input :10
Output :1
10 can only be represented as:
1+2+3+4
*/