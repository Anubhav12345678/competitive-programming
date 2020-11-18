
/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c
 occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".



*/



class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        vector<int> f{a,b,c};
        vector<int> l{0,0,0};
        int tot=a+b+c;
        for(int u=0;u<tot;u++)
        {
            for(int i=0;i<3;i++)
            {
                int j= (i+1)%3;
                int k = (i+2)%3;
                if((f[i]>=f[j]&&f[i]>=f[k]&&l[i]!=2)||(f[i]>0&&(l[j]==2||l[k]==2)))
                {
                    ans+='a'+i;
                    f[i]--;
                    l[i]++;
                    l[j]=0;
                    l[k]=0;
                    break;
                }
            }
        }
        return ans;
    }
};