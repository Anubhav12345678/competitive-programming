

/*

Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"



*/


class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res,tmp;
        stringstream str(s);
        string w;
        while(str>>w)
            tmp.push_back(w);
        int i=0,j=0,k=0,l=0,n=tmp.size();
        int maxlen = tmp[0].size();
        for(i=1;i<n;i++)
        {
            int x = tmp[i].size();
            maxlen = max(maxlen,x);
        }
        for(i=0;1;i++)
        {
            string t;
            for(j=0;j<n;j++)
            {
            char c = (k<tmp[j].size())?tmp[j][k]:' ';
                t.push_back(c);
            }
            j=t.size()-1;
            while(j>=0&&t[j]==' ')
                j--;
            if(j>=0)
            {
                t = t.substr(0,j+1);
                res.push_back(t);
            }
            k++;
            if(k>=maxlen) break;
        }
        return res;
        
    }
};