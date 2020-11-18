class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        int i,j,k,l,n;
        vector<string> res;
        for(auto w:words){
          n=w.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(i=0;i<n;i++){
                if(dp[i]==0) continue;
                for(j=i+1;j<=n;j++){
                    if((j-i)<n&&s.count(w.substr(i,j-i))) dp[j]=1;
                }
                
                if(dp[n]) { res.push_back(w); break;}
            }
        }
        
        return res;
    }
};
/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".


*/