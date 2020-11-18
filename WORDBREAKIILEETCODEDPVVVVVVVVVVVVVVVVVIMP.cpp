    class Solution {
public:
    unordered_map<string,vector<string>> mp;
    vector<string> combine(string &word,vector<string> &v){
        for(auto &s:v)
            s+=" "+word;
        return v;
    }
    vector<string> solve(string &a,unordered_set<string> &st){
        if(mp.find(a)!=mp.end()) return mp[a];
        vector<string> res;
        if(st.count(a))
            res.push_back(a);
        for(int i=1;i<a.size();i++){
            string w = a.substr(i);
            if(st.find(w)!=st.end()){
                string beg = a.substr(0,i);
                vector<string> v2 = solve(beg,st);
                vector<string> prev = combine(w,v2);
                res.insert(res.end(),prev.begin(),prev.end());
            }
        }
        return mp[a] = res;
    }
    vector<string> wordBreak(string a, vector<string>& b) {
        mp.clear();
        unordered_set<string> dict;
        for(auto s:b)
            dict.insert(s);
        return solve(a,dict);
    }
};
/*
Given a non-empty string s and a dictionary wordDict containing
 a list of non-empty words, add spaces in s to construct a sentence
  where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]


*/