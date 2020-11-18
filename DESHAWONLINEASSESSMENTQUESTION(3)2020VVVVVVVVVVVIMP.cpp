vector<string> encrypt(vector<int> &arr) {
	vector<string> ans;
	for (int n : arr) {
		if (n == 1) {
			ans.push_back("1");
			continue;
		}
		ostringstream oss;
		for (int i = 9; i >= 2; --i) {
			while (n % i == 0) {
				oss << i;
				n /= i;
			}
		}
		if (n == 1) {
			ans.emplace_back(oss.str());
			reverse(ans.back().begin(), ans.back().end());
		} else {
			ans.push_back("-1");
		}
	}
	return ans;
}