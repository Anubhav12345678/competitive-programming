class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        int i,j,k,l,a,b,c=0;
        bool tab[n][n];
        memset(tab,false,sizeof(tab));
        for(i=0;i<n;i++)
        {
            tab[i][i]=1;
            c++;
        }
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                tab[i][i+1]=1;
                c++;
            }
        }
        for(l=3;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                if(tab[i+1][j-1]&&s[i]==s[j])
                {
                    tab[i][j]=true;
                    c++;
                }
            }
        }
        return c;
    }
};