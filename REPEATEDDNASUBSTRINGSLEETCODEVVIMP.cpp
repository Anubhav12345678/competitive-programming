class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        map<string,int> m;
        for(int i=0;i<n-9;i++) m[s.substr(i,10)]++;
        for(auto it  = m.begin();it!=m.end();it++)
            if(it->second>1)
                res.push_back(it->first);
        return res;
    }
};