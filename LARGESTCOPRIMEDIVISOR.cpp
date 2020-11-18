int gcd(int a,int b)
{
    int s = min(a,b);
    int c = max(a,b);
    if(s==0)
    return c;
    else
    return gcd(s,c%s);
}
int Solution::cpFact(int A, int B) {
    if(gcd(A,B)==1)
    return A;
    if(A==B)
    {
        return 1;
    }
    int i,j,k,mini=-1;
    while(gcd(A,B)!=1)
    {
        A/= gcd(A,B);
    }
    // for(i=2;i*i<=A;i++)
    // {
    //     if(A%i==0&&gcd(B,i)==1)
    //     mini = max(mini,i);
    // }
    return A;
}
// or gfg sol
// CPP program to find the 
// Largest Coprime Divisor 

#include <bits/stdc++.h> 
using namespace std; 

// Recursive function to return gcd 
// of a and b 
int gcd(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0 || b == 0) 
        return 0; 

    // base case 
    if (a == b) 
        return a; 

    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 

// function to find largest 
// coprime divisor 
int cpFact(int x, int y) 
{ 
    while (gcd(x, y) != 1) { 
        x = x / gcd(x, y); 
    } 
    return x; 
} 

// divisor code 
int main() 
{ 
    int x = 15; 
    int y = 3; 
    cout << cpFact(x, y) << endl; 
    x = 14; 
    y = 28; 
    cout << cpFact(x, y) << endl; 
    x = 7; 
    y = 3; 
    cout << cpFact(x, y); 
    return 0; 
} 
