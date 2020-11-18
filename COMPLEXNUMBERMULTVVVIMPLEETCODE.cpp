class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i=0,j=0,k,l;
        int res1=0,res2=0,res3=0,res4=0;
        int sign=1;
        
        while(i<n&&a[i]!='+')
        {
            if(a[i]=='-')
            {
                sign*=-1;
                i++;
                continue;
            }
            else
            {
                res1 = res1*10+(a[i]-'0');
                i++;
            }
        }
        res1*=sign;
        sign=1;
        i++;
        while(i<n&&a[i]!='i')
        {
            if(a[i]=='-')
            {
                sign*=-1;
                i++;
                continue;
            }
            else
            {
                res2 = res2*10+(a[i]-'0');
                i++;
            }
        }
        res2*=sign;
        i=0;
        sign=1;
        while(i<m&&b[i]!='+')
        {
            if(b[i]=='-')
            {
                sign*=-1;
                i++;
                continue;
            }
            else
            {
                res3 = res3*10+(b[i]-'0');
                i++;
            }
        }
        res3*=sign;
        sign=1;
        i++;
        while(i<m&&b[i]!='i')
        {
            if(b[i]=='-')
            {
                sign*=-1;
                i++;
                continue;
            }
            else
            {
                res4 = res4*10+(b[i]-'0');
                i++;
            }
        }
        res4*=sign;
        sign=1;
        cout<<"res1 = "<<res1<<" res2 = "<<res2<<" res3= "<<res3<<" res4 = "<<res4<<endl;
        int x = (res1*res3-res2*res4);
        cout<<x<<endl;
        if(x<0) sign=-1;
        x = abs(x);
        string p = to_string(x);
        if(sign==-1)
            p.insert(p.begin(),'-');
        sign=1;
        int y = (res1*res4+res2*res3);
        cout<<y<<endl;
        if(y<0)
            sign=-1;
        y = abs(y);
        string q = to_string(y);
        if(sign==-1)
            q.insert(q.begin(),'-');
        q=q+"i";
        return p+"+"+q;
        
        
    }
};