/*

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .



*/






class Solution {
public:
    bool isdig(char a)
    {
        if(a>='0'&&a<='9')
            return 1;
        return 0;
    }
    int calculate(string s) {
        int n = s.size();
        int i,j,k,l;
        if(n==0)
            return 0;
        i=0,j=0;
        int num=0,res=0,sign=1;
        stack<int> st;
        while(i<n)
        {
            if(isdig(s[i]))
            {
                num=0;
                j=i;
                while(j<n&&isdig(s[j]))
                {
                    num=num*10+(s[j]-'0');
                    j++;
                }
                res+=sign*num;
                i=j;
            }
            else if(s[i]=='+')
            {
                sign=1;
                i++;
            }
            else if(s[i]=='-')
            {
                sign=-1;
                i++;
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
                i++;
            }
            else if(s[i]==')')
            {
                int sgn = st.top();
                st.pop();
                int prev = st.top();
                st.pop();
                res = prev+sgn*res;
                i++;
            }
            else
                i++;
        }
        return res;
    }
};