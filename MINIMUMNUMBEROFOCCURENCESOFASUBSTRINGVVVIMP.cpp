
/*

Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

*/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        int i,j,k,l,len;
        if(n==0)
            return 0;
        map<string,int> m;
        for(len=minSize;len<=maxSize;len++)
        {
            map<char,int> cnt;
            int ncnt=0;
            for(i=0;i<len-1;i++)
            {
                if(cnt[s[i]]==0)
                    ncnt++;
                cnt[s[i]]++;
            }
            for(i=len-1;i<n;i++)
            {
                if(!cnt[s[i]]++) ncnt++;
                if(ncnt<=maxLetters)
                    m[s.substr(i-len+1,len)]++;
                if(!--cnt[s[i-len+1]]) ncnt--;
            }   
        }
        int ans=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            ans = max(ans,it->second);
        }
        return ans;
    }
};