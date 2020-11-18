vector<int> Solution::lszero(vector<int> &A) {
    int i,j,k,l,st,en,s=0,maxlen,n;
    st=0,en=0,maxlen=0;
    n = A.size();
    map<int,int> presum;
    for(i=0;i<n;i++)
    {
        s+=A[i];
        if(A[i]==0&&maxlen==0)
        {
            st=i;
            en=i;
        maxlen=1;
        }
        else if(s==0)
        {
            st=0;
            en=i;
        maxlen=i+1;
        }
        if(presum.find(s)!=presum.end())
        {
           if(maxlen<i-presum[s])
           {
               en=i;
               st=presum[s]+1;
               maxlen = i-presum[s];
           }
        }
        else
        presum[s]=i;
    }
    vector<int> res(en-st+1);
    res.clear();
    s=0;
    for(i=st;i<=en;i++)
    {
        s+=A[i];
    res.push_back(A[i]);
    }
    if(s==0)
    return res;
    else
    {
        res.clear();
        return res;
    }
    
}
