class Solution {
public:
    int cnvt(string s)
    {
        int n = s.size();
        int i,j,k,l,res=0;
        for(i=n-1;i>=0;i--)
        {
            res+=(s[i]-'0')*(1<<i);
        }
        return res;
    }
    vector<int> grayCode(int n) {
        vector<string> res;
        vector<int> v;
        v.clear();
        res.push_back("0");
        if(n==0)
        {
            v.push_back(0);
            return v;
        }
        res.push_back("1");
        v.clear();
        if(n==1)
        {
            v.push_back(0);
            v.push_back(1);
            return v;
        }
        v.clear();
        int i,j,k,l;
        for(i=2;i<(1<<n);i=i<<1)
        {
            for(j=i-1;j>=0;j--)
                res.push_back(res[j]);
            for(j=0;j<i;j++)
                res[j] = "0"+res[j];
            for(j=i;j<2*i;j++)
                res[j] = "1"+res[j];
        }
        // vector<int> v;
        for(i=0;i<res.size();i++)
            v.push_back(cnvt(res[i]));
        return v;
        
    }
};