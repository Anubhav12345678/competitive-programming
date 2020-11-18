
/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s. Return the longest happy prefix of s .

Return an empty string if no such prefix exists.




*/




class Solution {
public:
    string longestPrefix(string s) {
        int i,j,k,l,n=s.size();
        if(n<=1)
            return "";
        vector<int> v(n,0);
        int len=0;
        for(i=1;i<n;i++)
        {
            if(s[i]==s[len])
            {
                len++;
                v[i] =len;
            }
            else
            {
                if(len)
                {
                    len = v[len-1];
                    i--;
                }
                else
                    v[i]=0;
            }
        }
        return s.substr(0,v[n-1]);
        
    }
};