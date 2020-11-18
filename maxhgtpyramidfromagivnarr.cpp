#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll  solve(ll a[],ll n)
{
	sort(a,a+n);
	ll cur_cnt = 0;
	ll cur_wid=0;
	ll prev_cnt = 1;
	ll prev_wid = a[0],ans=1;
	for(ll i=1;i<n;i++)
	{
		cur_wid+=a[i];
		cur_cnt+=1;
		if(cur_wid>prev_wid&&cur_cnt>prev_cnt)
		{
			prev_wid = cur_wid;
			prev_cnt = cur_cnt;
			cur_cnt=0;
			cur_wid = 0;
			ans++;
		}
		
	}
	return ans;
}
int main() {
	ll boxes[] = {10, 20, 30, 50, 60, 70}; 
    ll n = sizeof(boxes)/sizeof(boxes[0]); 
    cout <<solve(boxes, n) << endl; 
    return 0;
}