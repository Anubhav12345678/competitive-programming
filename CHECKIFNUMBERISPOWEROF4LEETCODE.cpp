class Solution {
public:
    bool isPowerOfFour(int num) {
       long long int n = num;
        if(n&&!(n&(n-1)))
        {
            int cnt=0;
            while(n>1)
            {
                n>>=1;
                cnt++;
            }
            return (cnt%2==0);
            
        }
        return 0;
    }
};