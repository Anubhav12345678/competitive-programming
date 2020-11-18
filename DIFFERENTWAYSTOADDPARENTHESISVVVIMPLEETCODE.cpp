
/*

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers 
and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

*/

class Solution {
public:
    
    
    bool isop(char c)
    {
        return c=='+'||c=='-'||c=='*'||c=='/';
    }
    vector<int> solve(string s,map<string,vector<int>> &m)
    {
        if(m.find(s)!=m.end())
            return m[s];
        int i,j,k,l;
        int n = s.size();
        vector<int> res;
        for(i=0;i<n;i++)
        {
            if(isop(s[i]))
            {
                vector<int> pre = solve(s.substr(0,i),m);
                vector<int> suf = solve(s.substr(i+1),m);
                for(j=0;j<pre.size();j++)
                {
                    for(k=0;k<suf.size();k++)
                    {
                       if(s[i]=='+')
                           res.push_back(pre[j]+suf[k]);
                        else if(s[i]=='-')
                            res.push_back(pre[j]-suf[k]);
                        else if(s[i]=='*')
                            res.push_back(pre[j]*suf[k]);
                    }
                }
            }
        }
        if(res.size()==0)
            res.push_back(atoi(s.c_str()));
        m[s]=res;
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        map<string,vector<int>> m;
        return solve(input,m);
    }
};