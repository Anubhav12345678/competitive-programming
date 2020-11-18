
/*
Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.




*/




class Solution {
public:
    bool ispalin(string s)
    {
        int n = s.size();
        int i=0,j=n-1;
        if(i>=j)
            return 1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return 0;
        }
        return 1;
    }
    bool canConstruct(string s, int k) {
        if(k==0&&s.size()==0)
            return 1;
        if(k==0||s.size()==0||(s.size()<k))
            return 0;
        // if(k==1&&ispalin(s))
        //     return 1;
        // if(k==1)
        //     return 0;
        if(k==s.size())
            return 1;
        int i,j,l,n=s.size();
        map<char,int> mp;
        for(i=0;i<n;i++)
            mp[s[i]]++;
        if(mp.size()==k)
            return 1;
        int odd=0,even=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2)
                odd++;
            else
                even++;
        }
        if(odd<=k)
            return 1;
        return 0;
        
        
    }
};