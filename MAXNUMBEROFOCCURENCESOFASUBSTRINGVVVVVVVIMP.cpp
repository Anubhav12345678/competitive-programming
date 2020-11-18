class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i,j,k,l,n=s.size();
        i=0;
        j=0;
        int res=0;
        int cnt[26]={0};
        int unique=0;
        unordered_map<string,int> mp;
        while(j<n)
        {
            if(++cnt[s[j++]-'a']==1) unique++;
            while(unique>maxLetters||(j-i)>minSize)
                if(--cnt[s[i++]-'a']==0) unique--;
            if((j-i)==minSize)
                res=  max(res,++mp[s.substr(i,minSize)]);
        }
        return res;
    }
};
/*

Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).






We need to find all substrings that meet specific criteria. We can do it in O(n) using a rolling window approach.
We can ignore maxSize - minSize substring will repeat the same or greater number of times.
Since we process all matching substring, we can just use a hash map to count their occurrences.


*/