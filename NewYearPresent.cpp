#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(i=0;i<n;i++)
int main()
{
    int n,a[301],i,j,k,l;;
    cin>>n;
    lp(i,n)cin>>a[i];
 
    lp(i,n)
    {
        if(a[i]>0)
        {
 
            if(i!=n-1)
            do
            {
                cout<<"PR";
                a[i]--;
                if(a[i]>0)
                    cout<<"L";
            }
            while(a[i]);
 
            else
 
            do
            {
                cout<<"P";
                a[i]--;
                if(a[i])
                    cout<<"LR";
            }
            while(a[i]);
 
        }
        else
        {
            if(i<n-1)cout<<"R";
 
        }
    }
}