#define ll long long
#define m 1000000007
/*

Let's define a function countUniqueChars(s) that returns the number of unique characters on s, for example if s = "LEETCODE" then "L", "T","C","O","D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

On this problem given a string s we need to return the sum of countUniqueChars(t) where t is a substring of s. Notice that some substrings can be repeated so on this case you have to count the repeated ones too.

Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

 

Example 1:

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10


*/
class Solution {
public:
    ll add(ll x,ll y)
    {
        return ((x%m)+(y%m))%m;
    }
    ll mult(ll x,ll y)
    {
        return ((x%m)*(y%m));
    }
    int uniqueLetterString(string s) {
        int i,j,k,l,n=s.size();
        vector<ll> cnt[26];
        cout<<"ok";
        for(i=0;i<n;i++)
        {
            char c = s[i];
            if(cnt[c-'A'].size()==0)
                cnt[c-'A'].push_back((-1)*1LL);
            cnt[c-'A'].push_back(i*1LL);
        }
        
        ll ans=0LL;
        
        for(i=0;i<26;i++)
        {
            if(cnt[i].size()==0) continue;
            cnt[i].push_back(n*1LL);
            for(j=1;j<cnt[i].size()-1;j++)
            {
                ll tmp = mult(cnt[i][j]-cnt[i][j-1],cnt[i][j+1]-cnt[i][j]);
                ans = add(ans,tmp);
            }
        }
        return ans;
    }
};