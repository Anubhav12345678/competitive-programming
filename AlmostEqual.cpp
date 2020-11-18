#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0 ;i<n ;++i)
#define repi(i,a,n) for(int i=a ;i<n ;++i)
 
 int a[200001];
 int main()
 {
     int n;
     cin>>n;
     //vector<int>  res;
     //res.resize(2*n);
     if(n&1)
     {
         cout<<"YES"<<endl;
         rep(i,n)
         {
             if(i&1)
             {
                 a[i]=2*n-i+1;
             }else a[i]=i+1;
         }
         rep(i,n)
         {
             if(i&1)a[i+n]=a[i]-1;
             else a[i+n]= a[i]+1;
         }
         rep(i,2*n)cout<<a[i]<<" ";
     }else cout<<"NO";
 }