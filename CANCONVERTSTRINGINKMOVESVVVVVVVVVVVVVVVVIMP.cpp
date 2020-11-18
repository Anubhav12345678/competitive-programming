class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()) return 0;
        int i,j,l,n=s.size();
        int cnt[26]={0};
        int ans=0;
        for(i=0;i<n;i++){
            int need = (t[i]-s[i]+26)%26;
            if(need!=0){
                ans = max(cnt[need]*26+need,ans);
                cnt[need]++;
            }
        }
        return ans<=k;
    }
};
/*
Given two strings s and t, your goal is to convert s into t in k moves or less.

During the ith (1 <= i <= k) move you can:

Choose any index j (1-indexed) from s, such that 1 <= j <= s.length and j has not
 been chosen in any previous move, and shift the character at that index i times.
Do nothing.
Shifting a character means replacing it by the next letter in the alphabet (wrapping
 around so that 'z' becomes 'a'). Shifting a character by i means applying the shift operations i times.

Remember that any index j can be picked at most once.

Return true if it's possible to convert s into t in no more than k moves, otherwise return false.

 

Example 1:

Input: s = "input", t = "ouput", k = 9
Output: true
Explanation: In the 6th move, we shift 'i' 6 times to get 'o'. And in the 7th move we shift 'n' to get 'u'.
*/