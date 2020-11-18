#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<iterator>
#define pb push_back
#define VI vector<ll>
// 4 8 15 16 23 42
int main() {
	ll i,j,t,k,l,m,n,ans=0;
	VI a,b,c,d,e,f;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		if(n==4)
		a.pb(i);
		if(n==8)
		b.pb(i);
		if(n==15)
		c.pb(i);
		if(n==16)
		d.pb(i);
		if(n==23)
		e.pb(i);
		if(n==42)
		f.pb(i);
	}
	i=0;
	j=0;
	k=0;
	l=0;
	m=0;
	n=0;
	// for(i=0;i<a.size();i++)
	// cout<<a[i]<<" ";
	// cout<<endl;
	// for(i=0;i<b.size();i++)
	// cout<<b[i]<<" ";
	// cout<<endl;
	// for(i=0;i<c.size();i++)
	// cout<<c[i]<<" ";
	// cout<<endl;
	// for(i=0;i<d.size();i++)
	// cout<<d[i]<<" ";
	// cout<<endl;
	// for(i=0;i<e.size();i++)
	// cout<<e[i]<<" ";
	// cout<<endl;
	// for(i=0;i<f.size();i++)
	// cout<<f[i]<<" ";
	// cout<<endl;
	
   while(i<a.size()&&j<b.size()&&k<c.size()&&l<d.size()&&m<e.size()&&n<f.size()) {
        if(a[i] < b[j]&&b[j]<c[k]&&c[k]<d[l]&&d[l]<e[m]&&e[m]<f[n]){
            ans++;
            i++,j++,k++,l++,m++,n++;
        }else {
            if(a[i] > b[j]){
                j++;
            }else if(b[j] > c[k]){
                k++;
            }else if(c[k] > d[l]){
                l++;
            }else if(d[l] > e[m]){
                m++;
            }else if(e[m] > f[n]){
                n++;
            }
        }
    }
    cout<<t-6*ans<<endl;
	
	// your code goes here
	return 0;
}
//or
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int i;
	vector<int> p({4, 8, 15, 16, 23, 42});

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
		// cout<<a[i]<<" ";
	}
	
	vector<int> seq(6);
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			++seq[0];
		} else {
			if (seq[a[i] - 1] > 0) {
				--seq[a[i] - 1];
				++seq[a[i]];
			}
		}
	}
	
	cout << n - seq[5] * 6 << endl;
	// for(i=0;i<6;i++)
	// cout<<seq[i]<<endl;
	
	return 0;
}