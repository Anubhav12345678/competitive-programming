#include<bits/stdc++.h>
using namespace std;
/*
Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system.
 These rectangles may intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

Unfortunately, Chef lost one vertex, and up until now, none of his fixes
 have worked (although putting an image of a point on a milk carton might 
 not have been the greatest idea after all…). Therefore, he gave you the 
 task of finding it! You are given the remaining 4N−1 points and you should find the missing one.



*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		vector<int> x, y;
		for(int i=0;i<4*n-1;++i) {
			int X,Y;
			cin>>X>>Y;
			x.push_back(X);
			y.push_back(Y);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		int ans_x=-1,ans_y=-1;
		auto find_odd=[&](vector<int>& x) -> int {
			int i,j;
			for(i=0;i<(int)x.size();i=j) {
				j=i;
				while(j<(int)x.size() && x[i]==x[j]) {
					j++;
				}	
				
				if((j-i)&1) return x[i];
			}
			return -1;
		};
		
		ans_x=find_odd(x);
		ans_y=find_odd(y);
		cout<<ans_x<<" "<<ans_y<<"\n";
	}
	return 0;
}