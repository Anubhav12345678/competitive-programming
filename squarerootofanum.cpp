//INTERVIEWBIT
int Solution::sqrt(int x) {
    if(x==0||x==1)
    return x;
    int st=1;
    long en=x;
    long mid;
    int ans;
    while(st<=en)
    {
        mid = st+(en-st)/2;
        if(mid*mid==x)
        return mid;
        else if(mid*mid<x)
        {
            ans=mid;
            st=mid+1;
        }
        else
        en=mid-1;
    }
    return ans;
}










#include <iostream> 
using namespace std; 
class gfg { 
    /*Returns the square root of n. Note that the function */
public: 
    float squareRoot(float n) 
    { 
        /*We are using n itself as initial approximation 
          This can definitely be improved */
        float x = n; 
        float y = 1; 
        float e = 0.000001; /* e decides the accuracy level*/
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
    } 
}; 
  
/* Driver program to test above function*/
int main() 
{ 
    gfg g; 
    int n = 50; 
    cout << "Square root of " << n << " is " << g.squareRoot(n); 
    getchar(); 
}