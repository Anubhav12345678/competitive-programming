


/*

You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty 
sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188


*/



class Solution {
public:
    int res;
    int cnt[26];
    void solve()
    {
        for(int i=0;i<26;i++)
        {
            if(cnt[i])
            {
                res++;
                cnt[i]--;
                solve();
                cnt[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        for(int i=0;i<tiles.size();i++) cnt[tiles[i]-'A']++;
        solve();
        return res;
    }
};