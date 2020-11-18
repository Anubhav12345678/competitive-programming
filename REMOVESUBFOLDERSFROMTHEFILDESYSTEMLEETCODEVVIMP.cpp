class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
       int n = folder.size();
        vector<string> f(folder.begin(),folder.end());
        int i,j,k,l;
        bool ok=0;
        vector<string> res;
        sort(f.begin(),f.end());
        res.clear();
        for(auto s:f)
        {
            auto t =s;
            ok=0;
            while(!s.empty())
            {
                while(!s.empty()&&s.back()!='/') s.pop_back();
                s.pop_back();
                auto it = lower_bound(f.begin(),f.end(),s);
                if(it!=f.end()&&*it==s)
                {
                    ok=1;
                    break;
                }
            }
            if(!ok)
                res.push_back(t);
        }
        return res;
    }
};