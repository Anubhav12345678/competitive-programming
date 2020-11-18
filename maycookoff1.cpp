#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll r,c,a[1001][1001],i,j;
	ll t;
	cin>>t;
	while(t--)
	{
		ll f=1;
		cin>>r>>c;
		for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        	cin>>a[i][j];
        for(i=0;i<r;i++)
        {
        	for(j=0;j<c;j++)
        	{
        		if((i==0||i==r-1)&&(j==0||j==c-1)&&a[i][j]>=2)
        			f=0;
        		else if((i==0||i==r-1||j==0||j==c-1)&&a[i][j]>=3)
                    f=0;
                else if(a[i][j]>=4)
                	f=0;
                if(f=0)
                	break;
        	}
        	if(f==0)
        		break;
        }
        if(f==0)
        	cout<<"Unstable";
        else
        	cout<<"Stable";
	}
}

