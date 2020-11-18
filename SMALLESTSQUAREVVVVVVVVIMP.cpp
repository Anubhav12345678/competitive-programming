#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
Assume that you are given an N*N matrix A and an integer K . You are required to find the length of the smallest square
 sub-matrix of A such that the sum of all the elements in the square sub-matrix is greater than or equals to K
  Print -1 if no such sub-square exists in matrix.


*/
int main() {
    ll i,j,k,l,x,n;
    cin>>n>>k;
    ll a[n+1][n+1];
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>x;
            a[i][j] = a[i][j-1]+x;
        }
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            a[i][j]+=a[i-1][j];
        }
    }
    ll h=n;
    l=1;
    ll ans=-1;
    while(h>=l)
    {
        ll mid = (h+l)/2;
        bool f=0;
        for(i=mid;i<=n;i++)
        {
            for(j=mid;j<=n;j++)
            {
                ll sum = a[i][j]+a[i-mid][j-mid]-a[i-mid][j]-a[i][j-mid];
                if(sum>=k)
                    f=1;
            }
        }
        if(f==1)
        {
            ans=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
    