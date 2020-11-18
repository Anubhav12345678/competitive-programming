class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i,j,k;
        vector<string> res;
        res.clear();
        int l = pattern.size();
        int n = str.size();
        i=0,j=0;
        while(i<n)
        {
            j=i;
            string s;
            // cout<<"i = "<<i<<endl;
            // cout<<"j = "<<j<<endl;
            s.clear();
            while(str[j]!=' '&&j<n)
                s.push_back(str[j++]);
            res.push_back(s);
            //  cout<<"i = "<<i<<endl;
            // cout<<"j = "<<j<<endl;
            i=j+1;
        }
        if(res.size()!=l)
            return false;
        map<char,string> mp;
        set<string> st;
        for(i=0;i<l;i++)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]=res[i];
                if(st.find(res[i])==st.end())
                    st.insert(res[i]);
                else
                    return false;
            }
            else if(mp[pattern[i]]!=res[i])
                return false;
        }
        return true;
    }
};