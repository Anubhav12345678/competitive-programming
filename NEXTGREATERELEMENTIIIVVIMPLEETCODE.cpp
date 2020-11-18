class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i,j,k,l,m=s.size();
        for(i=m-2;i>=0;i--)
            if(s[i]<s[i+1])
                break;
        if(i==-1) return -1;
        cout<<s<<endl;
        cout<<i<<endl;
        char c = s[i];
        char p = s[i+1];
        int ans=i+1;
        cout<<c<<" "<<p<<endl;
        for(j=i+2;j<m;j++)
            if(s[j]>c&&s[j]<p)
            {
                p=s[j];
                ans=j;
            }
        cout<<c<<" "<<p<<endl;
        char t= s[i];
        s[i]=p;
        s[ans]=t;
        sort(s.begin()+i+1,s.end());
        cout<<s<<endl;
        long long int r = stol(s);
        if(r>INT_MAX)
            return -1;
        return r;
    }
};