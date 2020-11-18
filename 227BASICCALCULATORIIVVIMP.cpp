class Solution {
public:
    bool isdig(char c)
    {
        if(c>='0'&&c<='9')
            return 1;
        return 0;
    }
    int calculate(string s) {
        int n = s.size();
        int i,j,k,l;
        if(n==0)
            return 0;
        char sign='+';
        stack<int> st;
        long long int num=0,res=0;
        char c;
        i=0,j=0;
        while(i<n)
        {
            c=s[i];
            if(isdig(c))
            {
                num=num*10+c-'0';
            }
            if(i+1==n||c=='+'||c=='-'||c=='*'||c=='/')
            {
                if(sign=='+')
                    st.push(num);
                else if(sign=='-')
                    st.push(-num);
                else if(sign=='*')
                {
                    int cpy = st.top();
                    st.pop();
                    cpy = cpy*num;
                    st.push(cpy);
                }
                else if(sign=='/')
                {
                    int cpy = st.top();
                    st.pop();
                    cpy = (int)(cpy/(float)num);
                    st.push(cpy);
                }
                sign=c;
                num=0;
            }
            i++;
        }
         res=0;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};