

/*
Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.



*/

// C++ program to count the steps 
// required to convert a number to 1 

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 

// function to calculate the number of actions 
int calculate_(string s) 
{ 
    // if the size of binary is 1 
    // then the number of actions will be zero 
    if (s.size() == 1) 
        return 0; 

    // initializing the number of actions as 0 at first 
    int count_ = 0; 
    for (int i = s.length() - 1; i > 0;) { 
        // start traversing from the last digit 
        // if its 0 increment the count and decrement i 
        if (s[i] == '0') { 
            count_++; 
            i--; 
        } 
        // if s[i] == '1' 
        else { 
            count_++; 

            // stop until you get 0 in the binary 
            while (s[i] == '1' && i > 0) { 
                count_++; 
                i--; 
            } 
            if (i == 0) 
                count_++; 

            // when encounter a 0 replace it with 1 
            s[i] = '1'; 
        } 
    } 
    return count_; 
} 

// Driver code 
int main() 
{ 
    string s; 
    s = "10000100000"; 

    cout << calculate_(s); 
    return 0; 
} 



class Solution {
public:
    int numSteps(string s) {
        int i,j,k,l,n=s.size();
        if(n==1)
            return 0;
        int cnt=0;
        for(i=n-1;i>0;)
        {
            if(s[i]=='0')
            {
                cnt++;
                i--;
            }
            else
            {
                cnt++;
                while(s[i]=='1'&&i>0)
                {
                    cnt++;
                    i--;
                }
                if(i==0)
                    cnt++;
                s[i]='1';
            }
        }
        return cnt;
    }
};