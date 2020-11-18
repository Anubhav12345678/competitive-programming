class Solution {
public:
    static bool comp(pair<string,int> a,pair<string,int> b)
    {
        if(a.first.size()!=b.first.size())
            return a.first.size()<b.first.size();
        else
            return a.second<b.second;
    }
    string arrangeWords(string text) {
        int i,j,k,l,n=text.size();
        text[0] = tolower(text[0]);
        stringstream str(text);
        string w;
        // text[0] = tolower(text[0]);
        vector<pair<string,int>> v;
        i=0;
        while(str>>w)
        {
            v.push_back({w,i++});
        }
        sort(v.begin(),v.end(),comp);
        string res="";
        for(i=0;i<v.size();i++)
            res+=v[i].first+" ";
        res.pop_back();
        res[0]=toupper(res[0]);
        return res;
        
    }
};  