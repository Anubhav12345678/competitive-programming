class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==0)
            return 0;
        int cnt=0,i,j,k,l,n=s.size();
        map<char,int> mp;
        for(i=0;i<n;i++)
            mp[s[i]]++;
        bool f=false;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            cnt+=(it->second/2)*2;
            if(it->second%2==1&&!f)
            {
                cnt++;
                f=true;
            }
        }
        return cnt;
    }
};