#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    cin>>s;
    int i,j,k,l,n=s.size(),op=0,cl=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(') op++;
        else
        {
            if(op==0) cl++;
            else
                op--;
        }
    }
    cout<<n-(op+cl)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
