/*
  convert [1 2 3 4 5] to [2 1 5 3 4] in two conditions
  1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players   
 */
#include<bits/stdc++.h>
using namespace std;
int main() {

	int n,i,j,k,l;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    int c=0;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]!=(i+1))
        {
            if(i>0&&a[i-1]==(i+1))
            {
                c++;
                a[i-1]=a[i];
                a[i]=i+1;
            }
            else if(i>1&&a[i-2]==(i+1))
            {
                c+=2;
                a[i-2]=a[i-1];
                a[i-1]=a[i];
                a[i]=i+1;
            }
            else
            {
                cout<<"NO\n";
                return  0;
            }
        }
    }
    cout<<"YES\n";
    cout<<c<<endl;
}