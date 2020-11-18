/*
Given the string s, return the size of the longest substring containing each vowel an even number of times. 
That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.






*/






class Solution {
public:
    int lst[100];
    int findTheLongestSubstring(string s) {
        int i,j,k,l;
        memset(lst,-1,sizeof(lst));
        int h=0;
        lst[h]=0;
        int cur=0,ans=0;
        for(auto c:s)
        {
            cur++;
            if(c=='a') h^=(1<<0);
            else if(c=='e') h^=(1<<1);
            else if(c=='i') h^=(1<<2);
            else if(c=='o') h^=(1<<3);
            else if(c=='u') h^=(1<<4);
            if(lst[h]>=0) ans = max(ans,cur-lst[h]);
            else
                lst[h] = cur;
        }
        return ans;
    }
};