#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	int c1=0,c2=0;
	for(i=0;i<n;i++){
		if(a[i]==1){
			c1++;
		}
	}
	int m=c1/2;
	c2=c1/2;
	c1=c1%2;
	
	int p=(c1+c2)/2 +1;
	cout <<p<<endl;
	return 0;
}