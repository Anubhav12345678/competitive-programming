/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]

*/


class Solution {
public:
    bool check(string s, int k){
        int c = 0;
        for (int i=0;i<s.size();i++){
            if (i!=k && s[i] == '('){ c+=1; }
            if (i!=k && s[i] == ')'){ c-=1; if (c<0){return false;}}
        }
        return c==0;
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
       vector<string> res;
        map<string,bool> mp1,mp2;
        if(check(s,-1))
        {
            res.push_back(s);
            return res;
        }
        mp1[s]=true;
        int i,j,k,l;
        while(!mp1.empty())
        {
            bool flag=0;
            for(auto it=mp1.begin();it!=mp1.end();it++)
            {
                string tmp = it->first;
                for(i=0;i<tmp.size();i++)
                {
                    string tmp2 = tmp;
                    tmp2.erase(i,1);
                    if(check(tmp,i)&&mp2.find(tmp2)==mp2.end())
                    {
                        res.push_back(tmp2);
                        flag=1;
                    }
                    mp2[tmp2]=true;
                }
            }
            if(flag)
                return res;
            else
            {
                mp1=mp2;
                mp2.clear();
            }
        }
        return res;
    }
};