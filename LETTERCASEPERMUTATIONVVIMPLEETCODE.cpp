

/*

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string. 
 Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]



*/



class Solution {
public:
    vector<string> res;
    map<string,bool> oc;
    bool isdigit(char c)
    {
        if(c>='0'&&c<='9')
            return 1;
        return 0;
    }
    void solve(string s,int st)
    {
        int i = st;
        while(i<s.size())
        {
            if(!isdigit(s[i]))
                break;
            i++;
        }
        if(i==s.size())
            return;
        s[i]= toupper(s[i]);
        string u = s;
        s[i] = tolower(s[i]);
        string l = s;
        if(!oc[u])
        {
            res.push_back(u);
            oc[u]=1;
        }
        if(!oc[l])
        {
            res.push_back(l);
            oc[l]=1;
        }
        solve(u,i+1);
        solve(l,i+1);
    }
    vector<string> letterCasePermutation(string S) {
        res.push_back(S);
        oc[S]=1;
        solve(S,0);
        return res;
    }
};