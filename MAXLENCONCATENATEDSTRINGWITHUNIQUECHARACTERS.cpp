class Solution {
public:
    bool valid(const string& s) {
        bool vis[26] = {0};
        for (int i = 0 ; i < s.size() ; ++i) {
            if (!vis[s[i]-'a']) vis[s[i]-'a'] = 1;
            else return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int best = 0;
        for (int mask = 0 ; mask < (1<<arr.size()) ; ++mask) {
            string tmp;
            for (int i = 0 ; i < arr.size() ; ++i)
                if (mask&(1<<i)) {
                    tmp += arr[i];
                }
            if (!valid(tmp)) continue;
            if (tmp.size() > best) best = tmp.size();
        }
        return best;
    }
};