typedef long long LL;
#define MOD 1000000007ll
int Solution::cntBits(vector<int> &A) {
    int ans=0,n=A.size();

    //traverse over all bits
    for(int i=0; i<31; i++){

        //count number of elements with ith bit = 0
        LL cnt=0;
        for(int j=0; j<n; j++)
            if((A[j]&(1<<i)))cnt++;

        //add to answer cnt*(n-cnt)*2
        ans += (cnt*((LL)n-cnt)*2)%MOD;
        if(ans>=MOD)ans-=MOD;

    }