class Solution {
public:
    vector<string> splitstring(string s,char c)
    {
        int i,j,k,l,n=s.size();
        vector<string> res;
        string tmp="";
        for(i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                if(tmp.size()) res.push_back(tmp);
                tmp="";
            }
            else
                tmp+=s[i];
        }
        if(tmp.size()) res.push_back(tmp);
        return res;
    }
    int longestSubstring(string s, int k) {
        int i,j,l,n=s.size();
        if(k==1)
            return n;
        if(s.size()<k)
            return 0;
        int cnt[26]={0};
        for(i=0;i<n;i++)
            cnt[s[i]-'a']++;
        char bdch = '*';
        for(i=0;i<26;i++)
            if(cnt[i]!=0&&cnt[i]<k)
            {
                bdch=i+'a';
                break;
            }
        if(bdch=='*') return n;
        vector<string> xx = splitstring(s,bdch);
        int ans=0;
        for(i=0;i<xx.size();i++) ans = max(ans,longestSubstring(xx[i],k));
        return ans;
    }
};