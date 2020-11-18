
/*






*/



class Solution {
public:
    bool chk(string a,string b)
    {
        int h1[26]={0};
        int h2[26]={0};
        int i,j,k,l,n1=a.size(),n2=b.size();
        for(i=0;i<n1;i++) h1[a[i]-'a']++;
        for(i=0;i<n2;i++) h2[b[i]-'a']++;
        for(i=0;i<26;i++) if(h1[i]!=h2[i]) return 0;
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int i,j,k,l;
        string sm,bg;
        cout<<"ok\n";
        // if(n1<n2)
        // {
        //     sm=s1;
        //     bg=s2;
        // }
        // else
        // {
        //     sm=s2;
        //     bg=s1;
        // }
        if(n2<n1) return 0;
        cout<<"ok\n";
        if(s2.find(s1)!=-1) return 1;
        cout<<"ok\n";
        for(i=0;i<n2-n1+1;i++)
        {
            cout<<"inloop\n"<<i<<endl;
            j=i+n1-1;
            string  p =s2.substr(i,n1);
            cout<<"p.size()="<<p.size()<<endl;
            cout<<"afterp\n";
            if(chk(p,s1))
                return 1;
        }
        return 0;
            
    }
};