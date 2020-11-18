class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i,j,k,l,n=s.size();
        if(n==1)
            return false;
        vector<int> divisor;
        for(i=n/2;i>=1;i--)
        {
            if(n%i==0)
                divisor.push_back(i);
        }
        for(auto x:divisor)
        {
            int cnt=0;
            string str = s.substr(0,x);
            bool chk=true;
            while(cnt<n)
            {
                if(s.substr(cnt,x)!=str)
                {
                    chk=false;
                    break;
                }
                cnt+=x;
                    
            }
            if(chk)
                return true;
        }
        return false;
    }
};