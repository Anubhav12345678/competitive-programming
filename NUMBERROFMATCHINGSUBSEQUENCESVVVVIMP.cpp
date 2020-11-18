/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].





*/









class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt=0;
        for(auto st: words)
        {
            bool is=1;
            int i=0;
            for(char c:st)
            {
                i  =S.find_first_of(c,i); // searches for the first occurence of character at or after pos 
                if(i==string::npos)
                {
                    is=false;
                    break;
                }
                i++;
            }
            if(is)
            cnt++;
        }
        return cnt;
    }
};