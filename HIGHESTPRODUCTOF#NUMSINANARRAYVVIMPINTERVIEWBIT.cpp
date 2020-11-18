int Solution::maxp3(vector<int> &A) {
    int i,j,k,l,n=A.size();
    if(n<3)
    return 0;
    if(n==3)
    {
        return (A[0]*A[1]*A[2]);
    }
    int neg=0,z=0;
    for(i=0;i<n;i++)
    {
        if(A[i]<0)
        neg++;
        if(A[i]==0)
        z++;
    }
    if(neg==n)
    {
        sort(A.begin(),A.end(),greater<>());
        return (A[0]*A[1]*A[2]);
    }
    if(z==n||(z+neg)==n)
    return 0;
    int pos=n-(z+neg);
    sort(A.begin(),A.end());
    // for(i=0;i<n;i++)
    // cout<<A[i]<<" ";
    if(pos==1)
    {
        if(neg==1)
        return 0;
        else
        return A[n-1]*A[0]*A[1];
    }
    if(pos==2)
    {
       if(neg==1)
       return 0;
       else if(neg>0)
       return A[n-1]*A[0]*A[1];
       else
       return 0;
    }
    else
    {
        return max((A[0]*A[1]*A[n-1]),(A[n-1]*A[n-2]*A[n-3]));
    }
}
