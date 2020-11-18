bool isanagram(string a,string b)
{
    if(a.size()!=b.size())
    return 0;
    int h1[26],h2[26],i,j,k;
    memset(h1,0,sizeof(h1));
    memset(h2,0,sizeof(h2));
    for(i=0;i<a.size();i++)
    h1[a[i]-'a']++;
    for(j=0;j<b.size();j++)
    h2[b[j]-'a']++;
    for(i=0;i<26;i++)
    if(h1[i]!=h2[i])
    return 0;
    return 1;
}
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    res.clear();
    vector<int> tmp;
    int i,j,k,l,n;
    n = A.size();
    map<string,int> m;
    for(i=0;i<n;i++)
    {
        if(m.find(A[i])!=m.end())
        continue;
        tmp.clear();
        tmp.push_back(i+1);
        
        for(j=i+1;j<n;j++)
        {
              if(isanagram(A[i],A[j])&&(m[A[j]]!=(j+1)))
              {
                  tmp.push_back(j+1);
                  m[A[j]]=j+1;
              }
        }
        res.push_back(tmp);
    }
    return res;
    
}
