#include<bits/stdc++.h>
using namespace std;
#include<string.h>
/*Given a string S, we need to write a program to check if it is possible to construct the given string S by performing any of the below operations any number of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to print the minimum steps required to form the string.*/
int main()
{
    int t; 
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        
        int n=str.size();
        int count=0;
        
        int i=n-1;
        while(i>=0)
        {
            if((i+1)%2==0 && (str.substr(0,(i+1)/2) == str.substr((i/2)+1,(i+1)/2)) )
            {
                count++;
                i/=2;
            }
            else
            {
                count++;
                i--;
            }
        }
        cout << count << endl;
    }
}
    