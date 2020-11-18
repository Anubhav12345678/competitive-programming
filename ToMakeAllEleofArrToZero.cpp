#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   int n;
   cin>>n;
   ll a[n];
   ll sum=0;
   for(int i=0;i<n;i++) {
   	cin>>a[i];
   	sum+=a[i];
   }
   if(sum%2!=0){
   	cout<<"NO";
   	return 0;
   }
   sort(a,a+n);
   if(a[n-1]<=sum-a[n-1]) cout<<"YES";
      else cout<<"NO";
   return 0;
}