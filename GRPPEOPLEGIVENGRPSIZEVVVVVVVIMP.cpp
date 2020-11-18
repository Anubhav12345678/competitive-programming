class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
       int i,j,k,l,n=gs.size();
        map<int,vector<int>> mp;
        for(i=0;i<n;i++)
        {
            mp[gs[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int m = it->first;
            vector<int> v = it->second;
            vector<int> tmp;
            int c= m;
            for(i=0;i<v.size();i++)
            {
                tmp.push_back(v[i]);
                if((i+1)%c==0)
                {
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
            
        }
        return res;
    }
};