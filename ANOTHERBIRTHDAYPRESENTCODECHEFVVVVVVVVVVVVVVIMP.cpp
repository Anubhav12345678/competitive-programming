#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int a[MAX], b[MAX];
/*
Chef got another sequence as a birthday present. He does not like this sequence very
 much because it is not sorted. Since you are a good programmer, Chef is asking for your help.

You are given a sequence A1,A2,…,AN and an integer K. You may perform any number of 
operations of the following type (in any order): choose a valid integer i and swap Ai with Ai+K. Can you sort the sequence this way?
*/
int main() {
	// freopen("1.in", "r", stdin); 
	// freopen("1.out", "w", stdout);

	int T;
	cin >> T;
	for(int t=1;t<=T;t++) {
	    int n, k;
	    cin >> n >> k;
	    for(int i=1;i<=n;i++) {
	        cin >> a[i]; b[i] = a[i];
	    }
	    sort(b + 1, b + n + 1);
	    string ans = "yes";
	    for(int i=1;i<=k;i++) {
	        vector <int> p, q;
	        for(int j=i;j<=n;j+=k) {
	            p.push_back(a[j]);
	            q.push_back(b[j]);
	        }
	        sort(p.begin(), p.end());
	        if(p != q) ans = "no";
	    }
	    cout << ans << '\n';
	}
	return 0;
}