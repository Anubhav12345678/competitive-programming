

/*

Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.



*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.empty()) return 0;
        int n = p.size();
        vector<int> dp(26,0);
        dp[p[n-1]-'a']=1;
        int len=1;
        int i,j,k,l;
        cout<<"ok\n";
        //dp[i] gives (i+'a') vale char se nikli substring jo ki s ki subtring ho skti h uski max len kya h// vvvimp
        for(i=n-2;i>=0;i--)
        {
            if(p[i]-p[i+1]==-1||(p[i]=='z'&&p[i+1]=='a'))
            {
                len++;
                dp[p[i]-'a'] = max(dp[p[i]-'a'],len);
            }
            else
            {
                dp[p[i]-'a'] = max(dp[p[i]-'a'],1);
                len=1;
            }
        }
        cout<<"ok\n";
        int ans=0;
        for(auto it:dp)
            ans+=it;
        return ans;
    }
};