class Solution {
public:
    /*
    Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".  

    */
    bool isanagram(int a[],int b[])
    {
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return 0;
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        int i,j,k,l,n=s.size(),m=p.size();
        if(n<m)
            return {};
        int a[26]={0};
        for(i=0;i<m;i++)
            a[p[i]-'a']++;
        vector<int> res;
        for(i=0;i<=s.size()-p.size();i++)
        {
            int b[26]={0};
            for(j=0;j<p.size();j++)
                b[s[i+j]-'a']++;
            if(isanagram(a,b))
                res.push_back(i);
        }
        return res; 
        
    }
};