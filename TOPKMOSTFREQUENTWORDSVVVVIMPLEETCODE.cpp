class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<int,vector<string>, greater <int> > m;
        unordered_map<string,int> occurances;
        for (int i = 0; i < words.size(); ++i) {
            if (occurances.find(words[i]) != occurances.end()) {
                occurances[words[i]]++;
            } else {
                occurances[words[i]] = 1;
            }
        }
        for (unordered_map<string,int>::iterator it=occurances.begin(); it!=occurances.end(); ++it) {
            m[it->second].push_back(it->first);
        }
        vector<string> ret(k);
        int c = 0;
        for (map<int,vector<string>>::iterator it=m.begin(); it!=m.end(); ++it) {
            sort(it->second.begin(),it->second.end());
            for (int j = 0; j < it->second.size() && c < k; ++j) {
                ret[c++] = it->second[j];
            }
            if (c >= k) break;
        }
        return ret;
    }
};