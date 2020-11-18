class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n = slots1.size(), m = slots2.size(), i, j, k, a, b, x;
		vector<int> ans;

		sort(slots1.begin(), slots1.end());
		sort(slots2.begin(), slots2.end());
		a = 0; b = 0;

		while ((a < n) && (b < m)) {
			x = max(slots1[a][0], slots2[b][0]);
			if ((slots1[a][1] - x >= duration) && (slots2[b][1] - x >= duration)) {
				ans = { x, x + duration };
				return ans;
			}


			if (slots1[a][1] == slots2[b][1]) a++, b++;
			else if (slots1[a][1] < slots2[b][1]) a++;
			else b++;
		}

		return ans;

    }
};