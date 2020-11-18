class Solution {
public:
    int solve(string s,set<string> &st){
        int maxi=0;
        for(int i=1;i<=s.size();i++){
            string k  = s.substr(0,i);
            if(st.find(k)==st.end()){
                st.insert(k);
                maxi  = max(maxi,1+solve(s.substr(i),st));
                st.erase(k);
            }
        }
        
        return maxi;
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        return solve(s,st);
    }
};
/*


User Accepted:2378
User Tried:4077
Total Accepted:2441
Total Submissions:7707
Difficulty:Medium
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you

*/