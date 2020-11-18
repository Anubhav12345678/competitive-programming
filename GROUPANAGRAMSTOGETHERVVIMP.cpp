class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = strs.size();
        int i,j,k,l;
        vector<string> cpy(strs.begin(),strs.end());
        for(i=0;i<n;i++)
            sort(cpy[i].begin(),cpy[i].end());
        map<string,vector<string>> m;
        for(i=0;i<n;i++)
        {
            if(m.find(cpy[i])==m.end())
            {
               vector<string> tmp;
                tmp.push_back(strs[i]);
                m.insert(make_pair(cpy[i],tmp));
            }
            else
            {
                m[cpy[i]].push_back(strs[i]);
            }
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};