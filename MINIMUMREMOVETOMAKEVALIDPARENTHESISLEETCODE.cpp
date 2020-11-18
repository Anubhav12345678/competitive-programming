class Solution {
public:
    string minRemoveToMakeValid(string s) {
        bool ok[100005];
        memset(ok,false,sizeof(ok));
        int i,j,k,l,n=s.size();
        stack<int> st;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.size())
                {
                    ok[st.top()]=1;
                    ok[i]=1;
                    st.pop();
                }
            }
        }
        string res="";
        for(i=0;i<n;i++)
        {
            if(s[i]=='('||s[i]==')')
            {
                if(ok[i])
                    res+=s[i];
            }
            else
                res+=s[i];
        }
        return res;
    }
};