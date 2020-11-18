#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll a[1000005],i,j,t,n;
    cin>>t;
    while(t--)
    {
        ll k=0,f=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
        cin>>a[i];
        k+=a[i];
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        ll lftsum=0;
        for(i=0;i<n;i++)
        {
            k-=a[i];
            // lftsum+=a[i];
            if(k==lftsum)
            {
                f=1;
                cout<<i+1<<endl;
                break;
            }
            lftsum+=a[i];
        }
        if(f==0)
        cout<<-1<<endl;
        
    }
	//code
	return 0;
}