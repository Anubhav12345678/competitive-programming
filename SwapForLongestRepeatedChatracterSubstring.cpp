//the just below sol is the best one
class Solution {
public:
    int maxRepOpt1(string text) {
       int n = text.length();
    // Length of repeted substring ends with text[i]
    vector<vector<int>> len1(n, vector<int>(26));
    // Length of repeated substring starts with text[i]
    vector<vector<int>> len2(n, vector<int>(26));
    vector<int> counts(26);
    int last = -1; // not a letter
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      const int c = text[i] - 'a';
      if (c == last) {
        ++l;
      } else { 
        last = c;
        l = 1;
      }      
      len1[i][c] = l;
      len2[i - l + 1][c] = l;
      ++counts[c];
      ans = max(ans, l);
    }
    
    for (int i = 1; i < n - 1; ++i) {
      int cl = text[i - 1] - 'a';
      int cr = text[i + 1] - 'a';
      int left = len1[i - 1][cl];
      int right = len2[i + 1][cr];
      int count = 0;      
      if (cl != cr) {
        // e.g. "c aaa b cccc" => "b aaa ccccc"
        count = max(left + (counts[cl] > left ? 1 : 0), 
                    right + (counts[cr] > right ? 1 : 0));
      } else {
        // e.g. "a c aaa b aaaa" => "b c aaaaaaaa"
        count = left + right;
        if (counts[cl] > count) ++count;
      }
      ans = max(ans, count);
    }
    
    return ans;
        
        
        
    }
};

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        map<char,int> mp;
        int len[n];
        memset(len,0,sizeof(len));
        for(int i=0;i<n;i++)
        {
            char cur=text[i];
            mp[cur]++;
        }
        int st=0,cnt=1,en=0,nxtst,res=0;
        while(st<n)
        {
            en = st+1;
            nxtst=st;
            cnt=1;
            char cur=text[st];
            bool isswap=0;
            while(en<n&&(!isswap||text[en]==cur)&&cnt<mp[cur])
            {
                if(text[en]!=cur)
                {
                    isswap=1;
                    nxtst=en;
                }
                cnt++;
                en++;
            }
            res = max(cnt,res);
            if(nxtst==st)
                st++;
            else
                st=nxtst;
        }
        return res;
        
        
        
    }
};







class Solution {
public:
    int maxRepOpt1(string text) {
        int cnt[26]={0};
        int i,j,k,l,res=0,count=1,st,en,nxtst;
        for(i=0;i<text.size();i++)
            cnt[text[i]-'a']++;
        res=0;
        st=0;
        while(st<text.size())
        {
            en=st+1;
            count=1;
            char cur = text[st];
            nxtst = st;
            bool isswap=false;
            while(en<text.size()&&(!isswap||cur==text[en])&&count<cnt[cur-'a'])
            {
                if(cur!=text[en])
                {
                    isswap=true;
                    nxtst=en;
                }
                count++;
                en++;
            }
            res = max(res,count);
            if(nxtst==st)st++;
            else st=nxtst;
        }
        return res;
        
    }
}