//Pamit Kr. Singh
//Jaypee University Of Information Technology,Waknaghat


#include<bits/stdc++.h>
#include<iostream>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int>v(n);
        
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        
        int i,j;
        if(n%2==0){j=n-2;i=n-1;}
        else{j=n-1;i=n-2;}
        
        for(int k=j;k>=0;k-=2)cout<<v[k]<<" ";
        for(int k=1;k<=i;k+=2)cout<<v[k]<<" ";
        cout<<endl;
    }
    return 0;
}