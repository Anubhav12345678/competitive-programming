/*
Aahad and Harshit are playing a special game known as "Game of three". In this game, there are an array of numbers. Both Aahad and 
Harshit 
select a number(one by one) from the array and add the element's value in their score. The selected number is removed from the array.
Initially, scores of both Aahad and Harshit are zero and Aahad selects the first number. Harshit selects the second number and 
so on till the array becomes empty.
Final score of Aahad is taken as 'A' and for Harshit it is 'B'.
If absolute value of (A-B) is divisible by 3, then Aahad will win, otherwise Harshit will win. (Assume both players play
 to win and make no mistakes).


*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,i,j,k,l,a=0,b=0;
    cin>>n;
    int v[n];
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]%3==1)
            a++;
        else if(v[i]%3==2)
            b++;
    }
    if(a%2==0&&b%2==0)
        cout<<"Aahad\n";
    else
        cout<<"Harshit\n";

	// Write your code here
}