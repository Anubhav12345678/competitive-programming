
/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]


*/


class Solution {
public:
    bool ispalin(string s)
    {
        int n = s.size();
        if(n==1) return 1;
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    void f(vector<vector<string>> &res,vector<string> &v,string s,int st)
    {
        if(st==s.size()-1)
        {
            res.push_back(v);
            return;
        }
        for(int i=st+1;i<s.size();i++)
        {
            string p = s.substr(st+1,i-st);
            if(ispalin(p))
            {
                v.push_back(p);
                f(res,v,s,i);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        f(res,v,s,-1);
        return res;
    }
};