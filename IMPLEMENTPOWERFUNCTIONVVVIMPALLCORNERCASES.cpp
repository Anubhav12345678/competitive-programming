



int Solution::pow(int x, int n, int d) {
    if (x == 0) return 0;
if (d == 0) return -1;
if (n == 0) return 1;
long long res = x;
long long rem_fix = 1;
while (n > 1)
{

  if (n % 2 == 1)
  {
    rem_fix = (rem_fix * res)%d;
  }
  res = ((res%d) * (res%d)) % d;
  n = n / 2;
}
res = (res *rem_fix) % d;
if (res < 0)
  res += d;
return res;
    // if(ans<0)
    // {
    //     return (ans+d)%d;
    // }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

//above is interviewbit sol
//below if leetcode sol
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
            return 1.0;
        if(n==0)
            return 1.0;
        if(n==INT_MIN&&x!=-1)
            return 0.0;
        int sign = (n<0)?-1:1;
        if(n!=INT_MIN)
        n = abs(n);
        double y = myPow(x,n/2);
        double a = y*y;
        if(n%2==0)
        {
            if(sign==-1)
            {
                return (1/a);
            }
            else
            {
                return a;
            }
        }
        else
        {
            if(sign==-1)
            {
                return (1/a)*(1/x);
            }
            else
            {
                return a*x;
            }
        }
        
        
    }
};