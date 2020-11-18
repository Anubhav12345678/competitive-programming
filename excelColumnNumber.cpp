long long int power(int n,int index)
{
    if(index==0)
    return 1;
    long long int x = power(n,index/2);
    if(index%2==0)
    return x*x;
    else
    return x*x*n;
}
int Solution::titleToNumber(string A) {
    int n = A.size();
    if(n==1)
    return (A[0]-'A')+1;
    int i,j,k;
    long long int s=0;
    s+=(A[n-1]-'A'+1);
    int p=1;
    for(i=n-2;i>=0;i--)
    {
        s+=power(26,p)*(A[i]-'A'+1);
        p++;
    }
    return  s;
}
