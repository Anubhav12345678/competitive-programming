#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define P 1000000000
using namespace std;


int main()
{
   long a[1000][1000];
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                a[i][j]=1;
            else if(i==j)
                a[i][j]=1;
            else
                a[i][j]=(a[i-1][j-1]%P + a[i-1][j]%P)%P;
        }
    }
   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int j=0;j<=n;j++)
            cout<<a[n][j]<<" ";
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}