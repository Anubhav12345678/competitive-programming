class Solution {
public:
    int numSquareSum(int n)
    {
        int res = 0;
        while(n>0)
        {
            res+=((n%10)*(n%10));
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        set<long long int> st;
        while(1)
        {
            n = numSquareSum(n);
            if(n==1)
                return true;
            if(st.find(n)!=st.end())
                return false;
            st.insert(n);
        }
    }
};