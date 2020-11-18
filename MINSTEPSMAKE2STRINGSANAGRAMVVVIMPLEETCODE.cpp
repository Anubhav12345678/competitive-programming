/*
Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.




*/





class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> ms, mt;
        for (auto c : s) ms[c]++;
        for (auto c : t) mt[c]++;
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            ret += abs(ms[c] - mt[c]);
        }
        return ret / 2;
    }
};