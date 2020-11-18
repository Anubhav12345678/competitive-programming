//another ib sol
//Divide the array into two parts for each i and calculate left max and right max for each i. Answer will be max of all lmax+rmax.
int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2) return 0;
    vector<int> sm(A.size());
    vector<int> lg(A.size());
    sm[0] = A[0];
    lg[A.size()-1] = A[A.size()-1];
    for(int i = 1; i < A.size(); ++i) {     
        sm[i] = min(A[i], sm[i-1]);     // calculate smallest from 0 till now
    }
    for(int j = A.size()-2; j >= 0; --j) {
        lg[j] = max(A[j], lg[j+1]);     // calculate largest from A.size()-1 till now
    }
    int lmax = INT_MIN, rmax = INT_MIN;
    rmax = lg[0]-A[0];                  // initialize rmax for right side
    int sol = rmax;
    for(int i = 0; i < A.size()-1; ++i) {
        lmax = max(lmax, A[i]-sm[i]);       // calculate leftside maximum from 0 till i
        rmax = lg[i+1]-A[i+1];              // calculate rightside maximum from i+1 to A.size()
        sol = max(sol, lmax + rmax);
    }
    lmax = max(lmax, A[A.size()-1]-sm[A.size()-1]);     // when loop ends, we need to calculate lmax for i = A.size()-1
    sol = max(sol, lmax);
    return sol;
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j,k,l,n=prices.size();
        if(n==0)
            return 0;
        int maxprice=prices[n-1],minprice=prices[0];
        int profit[n];
        memset(profit,0,sizeof(profit));
        for(i=n-2;i>=0;i--)
        {
            maxprice = max(maxprice,prices[i]);
            profit[i] = max(profit[i+1],maxprice-prices[i]);
        }
        for(i=1;i<n;i++)
        {
            minprice = min(minprice,prices[i]);
            profit[i] = max(profit[i-1],profit[i]+prices[i]-minprice);
        }
        return profit[n-1];
    }
};