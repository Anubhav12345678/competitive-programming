string multiplyStrings(string s1, string s2) {
    if(s1=="0"||s2=="0")
    return "0";
    int sign=1;
    if(s1[0]=='-')
    {
        sign*=-1;
        s1.erase(s1.begin());
    }
    if(s2[0]=='-')
    {
        sign*=-1;
        s2.erase(s2.begin());
    }
    int n1,n2,i_n1=0,i_n2=0,car=0,sum,i,j,k,x,y;
    n1 = s1.size();
    n2 = s2.size();
    vector<int> res(n1+n2,0);
    for(i=n1-1;i>=0;i--)
    {
        i_n2=0;
        sum=0;
        car=0;
         x=s1[i]-'0';
        for(j=n2-1;j>=0;j--)
        {
            y=s2[j]-'0';
            sum=x*y+res[i_n1+i_n2]+car;
            car = sum/10;
            res[i_n1+i_n2]=sum%10;
            i_n2++;
        }
        if(car>0)
        res[i_n1+i_n2]+=car;
        i_n1++;
    }
    k=res.size()-1;
    while(k>=0&&res[k]==0)
    k--;
    if(k==-1)
    return "0";
    string s="";
    while(k>=0)
    s+=to_string(res[k--]);
    if(sign==-1)
    s.insert(s.begin(),'-');
    return s;
    
    
    
   //Your code here
}
