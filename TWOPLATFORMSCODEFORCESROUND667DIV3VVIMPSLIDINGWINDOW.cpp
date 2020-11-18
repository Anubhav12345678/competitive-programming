#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
There are n points on a plane. The i-th point has coordinates (xi,yi). You have two horizontal platforms, both of length k. Each
 platform can be placed anywhere on a plane but it should be placed horizontally (on the same y-coordinate) and have integer borders.
  If the left border of the platform is (x,y) then the right border is (x+k,y) and all points between borders (including borders)
   belong to the platform.

Note that platforms can share common points (overlap) and it is not necessary to place both platforms on the same y-coordinate.

When you place both platforms on a plane, all points start falling down decreasing their y-coordinate. If a point collides with 
some platform at some moment, the point stops and is saved. Points which never collide with any platform are lost.

Your task is to find the maximum number of points you can save if you place both platforms optimally.

You have to answer t independent test cases.

For better understanding, please read the Note section below to see a picture for the first test case.


*/
int main() {
	ll i,j,k,n,t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll x[n];
		for(i=0;i<n;i++) cin>>x[i];
		sort(x,x+n);
		for(i=0;i<n;i++) {
			ll p;
			cin>>p;
		}
		j=n-1;
		ll r[n], l[n];
		for(i=n-1;i>=0;i--){
			while((x[j]-x[i])>k) j--;
			r[i] = j-i+1;
			if(i<n-1) r[i] = max(r[i],r[i+1]);
		}
		
		j=0;
		for(i=0;i<n;i++){
			while((x[i]-x[j])>k) j++;
			l[i] = i-j+1;
			if(i>0)
			l[i] = max(l[i],l[i-1]);
		}
		
		
		ll ans=1;
		for(i=0;i<n-1;i++)
		ans= max(ans,l[i]+r[i+1]);
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}