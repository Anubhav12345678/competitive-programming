class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i,j,k,l,n=s.size();
       bool dp[n+1];
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(i=1;i<=n;i++){
            for(j=i-1;j>=0;j--){
                if(dp[j]){
                    string w = s.substr(j,i-j);
                    if(st.find(w)!=st.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
        
        
    }
};
/*
Given a non-empty string s and a dictionary wordDict containing a
 list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


*/