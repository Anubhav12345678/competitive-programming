
/*


Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation
 of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]


*/




class Solution {
public:
    bool ispalin(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return 0;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        int i,j,k,l;
        map<string,int> mp;
        for(i=0;i<n;i++)
            mp[words[i]]=i;
        for(i=0;i<n;i++)
        {
            string s = words[i];
            reverse(s.begin(),s.end());
            if(mp.find(s)!=mp.end()&&mp[s]!=i)
                res.push_back({i,mp[s]});
            if(ispalin(s))
            {
                if(mp.find("")!=mp.end()&&mp[""]!=i)
                {
                    res.push_back({i,mp[""]});
                    res.push_back({mp[""],i});
                }
            }
            s=words[i];
            for(j=s.size()-1;j>0;j--)
            {
                if(ispalin(s.substr(j)))
                {
                    string p = s.substr(0,j);
                    reverse(p.begin(),p.end());
                    if(mp.find(p)!=mp.end()&&mp[p]!=i)
                    {
                        res.push_back({i,mp[p]});
                    }
                }
            }
            for(j=1;j<s.size();j++)
            {
              if(ispalin(s.substr(0,j)))
              {
                  string p = s.substr(j);
                  reverse(p.begin(),p.end());
                  if(mp.find(p)!=mp.end()&&mp[p]!=i)
                      res.push_back({mp[p],i});
              }
            }
        }
        return res;
    }
};