/*

Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.



*/



class Solution {
    int cnt[30];
public:
    string sortString(string s) {
        for (char c: s) 
            ++cnt[c - 'a'];
        string ans;
        int left = s.length();
        for (; left > 0; ){
            for (int i = 0; i < 26; ++i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
            for (int i = 25; i >= 0; --i)
                if (cnt[i]) --cnt[i], --left, ans.push_back(i + 'a');
        }
        return ans;
    }
};