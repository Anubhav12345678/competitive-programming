#include <bits/stdc++.h>
using namespace std;

int main() {
	int neg=0,i,j,k,l,n,m,pos=0,cnt=0;
	cin>>n;
	int prod=1;
	int maxneg=INT_MIN;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)
		{
			cnt++;
			continue;
		}
		if(a[i]<0){
			neg++;
			maxneg = max(maxneg,a[i]);
		}
		
		prod = prod*a[i];
	}
	
	if(cnt==n)
	cout<<0;
	else if(neg%2==1){
		if(neg==1&&cnt>0&&neg+cnt==n)
		cout<<0;
		else
		cout<<prod/maxneg;
	}
	else
	cout<<prod;
	// your code goes here
	return 0;
}