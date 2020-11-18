class Solution {
    string ans;
    unordered_set<string> vis;
    int n,a,b;
    bool isvisited(string s)
    {
        return vis.find(s)!=vis.end();
    }
    void visit(string s)
    {
        ans = min(ans,s);
        vis.insert(s);
    }
    string ro(string s,int x)
    {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+x);
        reverse(s.begin()+x,s.end());
        return s;
    }
    string add(string s,int x)
    {
        for(int i=1;i<s.size();i+=2)
        {
            char &c = s[i];
            c = '0'+(c-'0'+x)%10;
        }
        return s;
    }
public:
    void dfs(string s)
    {
        if(isvisited(s))
            return;
        visit(s);
        dfs(ro(s,b));
        dfs(add(s,a));
    }
    string findLexSmallestString(string s, int a, int b) {
        ans=s;
        this->a=a;
        this->b=b;
        n=s.size();
        dfs(s);
        dfs(s);
        return  ans;
    }
};
/*
You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

 

Example 1:

Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
​​​​​​​Add:    "5121"
​​​​​​​Rotate: "2151"
​​​​​​​Add:    "2050"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "2050".





*/