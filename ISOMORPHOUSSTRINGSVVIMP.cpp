class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m!=n)
            return false;
        int i,j,k,l;
        bool mark[256];
        memset(mark,false,sizeof(mark));
        int mapped[256];
        memset(mapped,-1,sizeof(mapped));
        for(i=0;i<n;i++)
        {
            if(mapped[s[i]]==-1)
            {
                if(mark[t[i]])
                    return false;
                mark[t[i]]=true;
                mapped[s[i]]=t[i];
            }
            else if(mapped[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};