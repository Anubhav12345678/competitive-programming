#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define all(a) a.begin(),a.end()
#define bitcnt(x) __builtin_popcountll(x)
#define MOD 1000000007
#define total 5000005
#define M 1000000000001
#define NIL 0
#define MAXN 200001
#define EPS 1e-5
#define INF (1<<28)
/*

You have reached the final level of Hunger Games and as usual a tough task awaits you. You have a circular 
dining table and N hungery animals.You need to place them on the table.Each animal has a hunger value.
You can place the animals in any order on the circular table.Once you place them you need to calculate the
 Danger value of your arrangement.
The danger value of the arrangement is the maximum difference of hunger values of all the adjacent seated animals
.You need to keep this danger value as low as possible.


*/
typedef unsigned long long int uint64;
typedef long long int int64;
int main(){
	int n,i,j;
	vector<int>v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		v.pb(j);
	}
	sort(all(v));
	int ans=0;
	for(i=0;i<v.size();i++){
		if(i+2>=n)
		break;
		ans=max(ans,v[i+2]-v[i]);
	}
	cout<<ans;
	return 0;
}