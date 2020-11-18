


/*
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.



*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,j,l,n=s.size();
        int ans=0;
        int left=0,right=0;
        int cnt[26]={0};
        int maxcnt=0,maxlen=0;
        for(right=0;right<n;right++)
        {
            cnt[s[right]-'A']++;
            maxcnt = max(maxcnt,cnt[s[right]-'A']);
            while(right-left+1-maxcnt>k)
            {
                cnt[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};