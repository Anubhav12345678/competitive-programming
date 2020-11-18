class Solution {
public:
    vector<string> solve(string s,char c)
    {
        int i,j,k,l,n=s.size();
        vector<string> res;
        string tmp="";
        for(i=0;i<n;i++)
        {
            if(s[i]!=c)
                tmp.push_back(s[i]);
            else{
                res.push_back(tmp);
                tmp.clear();
            }
        }
        if(!tmp.size()==0)
            res.push_back(tmp);
        return res;
    }
    string simplifyPath(string path) {
        int i,j,k,l,n=path.size();
        vector<string> st;
        vector<string> v = solve(path,'/');
        // reverse();
        for(auto x:v)
        {
            // cout<<x.size()<<endl;
            // cout<<x<<endl;
            if(x=="."||x=="") continue;
            else
            {
                if(x==".."&&!st.empty())
                    st.pop_back();
                else if(x!="..")
                    st.push_back(x);
            }
        }
        
        // cout<<st.size();
        string res="";
        for(auto x:st)
        {
            res+="/"+x;
        }
        return (res.size()==0)?"/":res;
        
        
        
        
    }
};