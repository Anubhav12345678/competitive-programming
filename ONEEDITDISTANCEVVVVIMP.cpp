#include "solution.hpp"
using namespace std;

/*
Given two strings s0 and s1 determine whether they are one or zero edit distance away. An edit can be described as deleting a character, adding a character, or replacing a character with another character.

Constraints

n ≤ 100,000 where n is the length of s0.
m ≤ 100,000 where m is the length of s1.


*/
class Solution {
    public:
    bool solve(string s0, string s1) {
        // Write your code here
        int i,j,k,l,n = s0.size();
        int m = s1.size();
        if(n==0&&m==0) return 1;
        if(n==0&&m!=0) return m==1;
        if(n!=0&&m==0) return n==1;
        if(n==0||m==0) return 0;
        i=0;
        j=0;
        int cnt=0;
        while(i<n&&j<m){
            if( s0[i]!=s1[j])
            {
                cout<<"i = "<<i<<"  j = "<<j<<endl;
                cnt++;
                if(cnt==2) return 0;
                if(m>n)
                j++;
                else if(n>m)
                i++;
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                i++;
                j++;
            }
        }
        
        if(i<n||j<m) cnt++;
        return cnt<=1;
    }
};
