class Solution {
public:
    string reversestring(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            char c = s[i];
            s[i]=s[j];
            s[j]=c;
            i++;
            j--;
            
        }
        return s;
    }
    string reverseParentheses(string s) {
        int n  =s.size();
        int i,j,k,l,beg=0,end=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                beg=i;
            if(s[i]==')')
            {
                end=i;
                string tmp = s.substr(beg+1,end-beg-1);
                return reverseParentheses(s.substr(0,beg)+reversestring(tmp)+s.substr(end+1));
            }
        }
        return s;
    }
};