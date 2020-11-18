class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i,j,k,l,n=s.size();
        int maxind=-1,lastind=0;
        vector<int> pos(26,-1);
        for(i=0;i<n;i++) pos[s[i]-'a']=i;
        vector<int> res;
        for(i=0;i<n;i++){
            maxind = max(maxind,pos[s[i]-'a']);
            if(i==maxind){
                res.push_back(maxind-lastind+1);
                lastind = i+1;
            }
        }
        return res;
    }
};
/*
A string S of lowercase English letters is given. We want to partition 
this string into as many parts as possible so that each letter appears 
in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

*/