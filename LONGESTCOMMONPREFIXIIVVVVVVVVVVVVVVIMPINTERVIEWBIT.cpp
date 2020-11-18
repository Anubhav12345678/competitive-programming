#define ll long long
const ll mod = 1e9+7;
int Solution::LCPrefix(vector<string> &A, int B) {
    
    ll i,j,k,l,n=A.size();
    k=(ll)B;
    ll ans=0LL;
    for(i=0;i<n;i++)
    A[i] = A[i].substr(0,k);
    
    for(i=0;i<n;i++)
    {
        j=i;
        while(j<n&&A[j]==A[i]) j++;
        ans = (ans+((j-i)*(j-i+1))/2)%mod;
        i=j-1;
    }
    
    return ans%mod;
}
/*
Defining substring
For a string P with characters P1, P2 ,…, Pq, let us denote by P[i, j] the substring Pi, Pi+1 ,…, Pj.

Defining longest common prefix
LCP(S1, S2 ,…, SK), is defined as largest possible integer j such that S1[1, j] = S2[1, j] = … = SK[1, j].

You are given an array of N strings, A1, A2 ,…, AN and an integer K. Count how many indices (i, j) exist such that 1 ≤ i ≤ j ≤ N
 and LCP(Ai, Ai+1 ,…, Aj) ≥ K. Print required answer modulo 109+7.

Note that K does not exceed the length of any of the N strings. K <= min(len(A_i)) for all i

For example,

A = ["ab", "ac", "bc"] and K=1.

LCP(A[1, 1]) = LCP(A[2, 2]) = LCP(A[3, 3]) = 2
LCP(A[1, 2]) = LCP("ab", "ac") = 1
LCP(A[1, 3]) = LCP("ab", "ac", "bc") = 0
LCP(A[2, 3]) = LCP("ac", "bc") = 0

So, answer is 4.
Return your answer % MOD = 1000000007



*/