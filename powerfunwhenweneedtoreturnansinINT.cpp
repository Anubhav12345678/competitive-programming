 long long int power(int x,int n,int d)
{
    if(n==0)
    return 1;
    // x = x%d;
    long long int p = power(x,n/2,d)%d;
    if(p<0)
    p = d+p%d;
    if(n%2==0)
    return (p*p)%d;
    else
    return ((p*p)%d*x)%d;
}
int Solution::pow(int x, int n, int d) {
    if(x==0)
    return 0;
    if(d!=0)
    {
      int p = (int)power(x,n,d)%d;
      if(p<0)
      return d+p%d;
      return p%d;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
