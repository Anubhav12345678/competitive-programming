class Solution {
public:
    // map<char,int> mp;
    // static bool comp(char a,char b)
    // {
    //     return mp[a]>mp[b];
    // }
    string frequencySort(string s) {
        int n = s.size();
        int i,j,k,l;
        map<char,int> mp;
        for(i=0;i<n;i++)
            mp[s[i]]++;
        string p;
        map<int,vector<char>> mp2;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            char c = it->first;
            int x = it->second;
            mp2[x].push_back(c);
        }
        for(auto it = mp2.begin();it!=mp2.end();it++)
        {
            vector<char> v = it->second;
            int x = it->first;
            for(i=0;i<v.size();i++)
            {
                char c=v[i];
                int f = x;
                while(x--)
                    p.push_back(c);
                x=f;
            }
        }
        reverse(p.begin(),p.end());
        return p;
        
    }
};