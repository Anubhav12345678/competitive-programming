#include <bits/stdc++.h>
using namespace std;
int minswap(char a[],int n){
    vector<int>v;
     for(int i=0;i<n;i++)
         if(a[i]=='[')
         v.push_back(i);
    int count=0,p=0,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]=='[')
         {  ++count;++p;}
    else if(a[i]==']')
           --count;
      if(count<0){
         sum+=v[p]-i;
        swap(a[i],a[v[p]]);
         ++p;count=1;
      }        
    }
	return sum;    
}
int main() {
	int x;
	cin>>x;
	while(x--){
	    int n;
	    cin>>n;
	    char a[n];
	    for(int i=0;i<n;i++)
	      cin>>a[i];
	   cout<<minswap(a,n)<<"\n";
	}
	return 0;
}