string solve(string s) {
    int i,j,k,l,n=s.size();
    vector<int> brack(n);
    stack<int> st;
    bool f=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        st.push(i);
        else if(s[i]==')')
        {
            int x = st.top();
            st.pop();
            // if(i==x+1||i==x+2) continue;
            // f=1;
            // cout<<"x = "<<x<<" i = "<<i<<endl;
            brack[x]=i;
            brack[i]=x;
        }
    }
    // if(f==0) {
    //     string ans;
    //     for(i=0;i<n;i++)
    //     if(s[i]!='('&&s[i]!=')') ans+=s[i];
    //     return ans;
    // }
    string ans;
    int dir=1;
    for(i=0;i<n;i+=dir)
    {
        if(s[i]=='('||s[i]==')')
        {
            i=brack[i];
            if(dir==-1)
            dir=1;
            else
            dir=-1;
        }
        else
        ans.push_back(s[i]);
    }
    return ans;
}
/*
You are given a string s containing lowercase alphabet characters as well as brackets "(" and ")". Recursively reverse every string enclosed between brackets "(...)" and return the resulting string.


*/