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
int nod(int n)
{
    if(n==0)
    return 0;
    else
    return 1+nod(n/10);
}
int Solution::reverse(int A) {
    if(sizeof(A)>sizeof(int))
    return 0;
    if(A>-10&&A<10)
    return A;
    int sign = 1;
    if(A<0)
    sign*=-1;
    A = abs(A);
    long long int rev = 0,rem = 0;
    int tmp = A;
    // int n = nod(A);
    // long long int x = power(10,n-1);
    while(tmp>0)
    {
        rem = tmp%10;
        rev = rev*10+rem;;
        tmp/=10;
    }
    // cout<<rev<<endl;
    if(rev>INT_MAX||rev<INT_MIN)
    return 0;
    return (rev*sign);
    
    
    
}
