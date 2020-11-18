/*


A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".


*/




#define ll long long
#define pb push_back
class Solution {
public:
    map<int,vector<string>> mp;
    void fill()
    {
        string s1="a",s2="b",s3="c";
        mp[1].pb(s1);
        mp[1].pb(s2);
        mp[1].pb(s3);
        sort(mp[1].begin(),mp[1].end());
        for(int i=2;i<=10;i++)
        {
            vector<string> v=  mp[i-1];
            vector<string> res;
            for(int j=0;j<v.size();j++)
            {
                string s= v[j];
                if(v[j][i-2]=='a')
                {
                    s.pb('b');
                    mp[i].pb(s);
                    s.pop_back();
                    s.pb('c');
                    mp[i].pb(s);
                    s.pop_back();
                }
                else if(v[j][i-2]=='b')
                {
                    s.pb('c');
                    mp[i].pb(s);
                    s.pop_back();
                    s.pb('a');
                    mp[i].pb(s);
                    s.pop_back();
                }
                else if(v[j][i-2]=='c')
                {
                    s.pb('a');
                    mp[i].pb(s);
                    s.pop_back();
                    s.pb('b');
                    mp[i].pb(s);
                    s.pop_back();
                }
            }
            sort(mp[i].begin(),mp[i].end());
        }
    }
    string getHappyString(int n, int k) {
        mp.clear();
        fill();
        if(mp[n].size()<k)
            return "";
        return mp[n][k-1];
    }
};