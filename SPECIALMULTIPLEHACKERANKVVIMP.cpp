

/*

You are given an integer N. Can you find the least positive integer X made up of only 9's and 0's, such that, X is a multiple of N?

Update

X is made up of one or more occurences of 9 and zero or more occurences of 0.

Input Format
The first line contains an integer T which denotes the number of test cases. T lines follow.
Each line contains the integer N for which the solution has to be found.

Output Format
Print the answer X to STDOUT corresponding to each test case. The output should not contain any leading zeroes.

Constraints
1 <= T <= 104
1 <= N <= 500

Sample Input

3
5
7
1
Sample Output

90
9009
9


*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int i,j,k,l,bin[10001]={0},t,x,n;
    for(i=1;i<10000;i++)
    {
        j=i;
        x=1;
        while(j)
        {
            bin[i] = bin[i]+(j%2)*x;
            j/=2;
            x*=10;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;;i++)
        {
            if((bin[i]*9)%n==0)
            break;
        }
        cout<<bin[i]*9<<endl;
    }
}