#include<iostream>

#define rep(i,j,k) for(i=j;i<k;i++)
#define invrep(i,j,k) for(i=j-1;i>=k;i--)

#define mx 100005

typedef long long int ll;

using namespace std;
int main(){
	ll i,j,k,p,q,r,a,b,c,n,t;
	ll A[mx];
	cin>>t;
	cin>>n;
	while(t--){
		cin>>n>>k;
		rep(i,0,n) cin>>A[i];
		if (k==2)
		{
			q=0;
			rep(i,0,n-2){
				if (A[i]==A[i+2])
				{
					q=1;
					break;
				}
			}
			if (q==1)
			{
				cout<<"NO\n";
				continue;
			}else{
				cout<<"YES\n";
			}
		}else{
			cout<<"YES\n";
		}
		if (A[0]==-1)
		{
			if (A[1]!=1)
			{
				A[0]=1;
			}else{
				A[0]=2;
			}
		}
		rep(i,1,n-1){
			if (A[i]!=-1)
			{
				continue;
			}
			if (A[i-1]!=1&&A[i+1]!=1)
			{
				A[i]=1;
				continue;
			}
			if (A[i-1]!=2&&A[i+1]!=2)
			{
				A[i]=2;
				continue;
			}
			if (A[i-1]!=3&&A[i+1]!=3)
			{
				A[i]=3;
				continue;
			}
		}
		if (A[n-1]==-1)
		{
			if (A[n-2]!=1)
			{
				A[n-1]=1;
			}else{
				A[n-1]=2;
			}
		}
		rep(i,0,n) cout<<A[i]<<" ";
		cout<<"\n";
	}
}