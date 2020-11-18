/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly
 k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat 
numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".




*/




class Solution {
public:
    string decodeString(string s) {
        int i,j,k,n=s.size();
        // cout<<"s = "<<s<<endl;
        vector<int> v;
        int l=-1;
        int r=-1;
        for(i=n-1;i>=0;i--)
            if(s[i]=='[')
            {
                l=i;
                break;
            }
        if(l!=-1)
        {
            
            for(i=l;i<n;i++)
                if(s[i]==']')
                {
                    r=i;
                    break;
                }
            j=l-1;
            k=1;
            int x=0;
            while(j>=0&&s[j]>='0'&&s[j]<='9')
            {
                x = (s[j]-'0')*k+x;
                k*=10;
                j--;
                
            }
            
            string t = s.substr(l+1,r-l-1);
            cout<<t<<endl;    
            string cpy=t;
            for(i=1;i<x;i++)
                t+=cpy;
            if(j==-1)
                return decodeString(t+s.substr(r+1));
            l=j+2;
            return decodeString(s.substr(0,l-1)+t+s.substr(r+1));
        }
        else if(s[0]>='0'&&s[0]<='9')
        {
            int val=0;
            i=0;
            while(i<n&&s[i]>='0'&&s[i]<='9')
            {
                val = val*10+(s[i]-'0');
                    i++;
            }
            string t = s.substr(i);
            string cpy=t;
            while(--val)
                t+=cpy;
            return t;
        }
        return s;
        
    }
};