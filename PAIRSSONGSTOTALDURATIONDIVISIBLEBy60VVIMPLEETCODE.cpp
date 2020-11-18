typedef long long ll;
typedef long double ld;
class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
  	int n = time.size();
  	vector<int> cnt(60);
  	ll ans = 0;
  	for (int i = 0; i < n; ++i) {
  		int t = time[i] % 60;
  		ans += cnt[(60 - t) % 60];
  		++cnt[time[i] % 60];
		}
		return ans;
  }