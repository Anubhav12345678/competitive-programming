class Solution {
public:
    vector<vector<int>> reconstructMatrix(int uu, int ll, vector<int>& c) {
       vector<vector<int>> ans(2, vector<int>(c.size()));
        for (int i = 0; i < c.size(); i++) {
            if (c[i] == 0)continue;
            if (c[i] == 1) {
                if (uu > ll) {
                    uu--;
                    
                ans[0][i] = 1;
                } else {
                    ll--;
                    
                ans[1][i] = 1;
                    
                }
            } else {
                ans[0][i] = ans[1][i] = 1;uu--;ll--;
}
        }
            if (uu || ll)
                return vector<vector<int>>();
        return ans;
    }
};