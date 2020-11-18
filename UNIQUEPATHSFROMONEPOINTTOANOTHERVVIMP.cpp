class Solution {
public:
    // long long int fact(int n)
    // {
    //     if(n<=0)
    //         return 1;
    //     return n*fact(n-1);
    // }
    int uniquePaths(int m, int n) {
       int mod = 1000000007;
       long long int res=1;
        for(int i=n;i<m+n-1;i++)
        {
            res*=i;
            res/=(i-n+1);
        }
        return (int)res;
           
    }
};