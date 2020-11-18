//** aman**/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(int i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main(){
	int n,K;cin>>n>>K;
	int a[n+1][n+1];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}cout<<endl;
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=min(i,j);k++){
				int x=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
				if(x>=K){
					cout<<"YES"<<endl;
					cout<<i-k+1<<" "<<i-k+1<<" "<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
}