#include<bits/stdc++.h>
using namespace std;

int a[1000001];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            if(a[abs(a[i])-1]>0)
                a[abs(a[i])-1]=-a[abs(a[i])-1];
                else
                    cout<<abs(a[i])<<" ";
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
                cout<<i+1<<endl;
        }
    }
}