#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
//prob statement below
bool isdig(char c)
{
    return c>='0'&&c<='9';
}
void solve(vector<string> &res,string cur,string &s,int pos,int cnt)
{
    if(pos==s.size())
    {
        if(cnt>0)
            cur+=to_string(cnt);
        res.push_back(cur);
        return;
    }
    else
    {
        solve(res,cur,s,pos+1,cnt+1);
        // cur+=((cnt>0)?to_string(cnt):"");
        // cur.push_back(s[pos]);
        // string st(1,s[pos]);
        // solve(res,cur,s,pos+1,0);
        string st = cur+((cnt>0)?to_string(cnt):"");
        st.push_back(s[pos]);
        solve(res,st,s,pos+1,0);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<string> res;
    string cur="";
    ll n = s.size();
    solve(res,cur,s,0,0);
    sort(res.begin(),res.end());
    for(ll i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}
/*
Piku loves the idea of using regexes to represent words but doesn't like the use of '*' and '?'.

So he decided to come up with his own method of representing words.

In his method, a substring of length , can be replaced with the digit , with the added condition that no 2 digits can be adjacent to each other in the result.

So, for example, the word "piku" can be written as:

{"piku", "1iku", "p1ku", "pi1u", "pik1", "2ku", "p2u", "pi2", "1i1u", "1ik1", "p1k1", "1i2", "2k1", "3u", "p3", "4"}

Notice that strings like "p21" , "22", "21u" etc. do not satisfy the required property since they have adjacent digits together, so they are NOT present in the final answer.

So basically, the requirements are:

Given a string, you need to generate all possible sequences where a substring of length  is replaced with the digit .

Also, no 2 digits can be adjacent to each other in the final set of results.

Note 1: The string can contain a mix of uppercase and lowercase aplhabets.

Note 2: You are required to print the output in ASCII sorted order.

So, for the input string "piku", the actual output would be:

1i1u
1i2
1ik1
1iku
2k1
2ku
3u
4
p1k1
p1ku
p2u
p3
pi1u
pi2
pik1
piku 



*/