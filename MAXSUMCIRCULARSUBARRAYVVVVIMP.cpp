
/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



*/



class Solution {
public:
    int solve(vector<int> v)
    {
        int i,j,k,l,n=v.size();
        int maxsofar=0,maxtillhere=0;
        for(i=0;i<n;i++)
        {
            maxtillhere+=v[i];
            if(maxtillhere<0)
                maxtillhere=0;
            maxsofar=max(maxsofar,maxtillhere);
        }
        if(maxsofar==0)
        {
            sort(v.begin(),v.end());
            return v[n-1];
        }
        return maxsofar;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int sum=0;
        int ans = solve(A);
        for(i=0;i<n;i++)
        {
            sum+=A[i];
            A[i]=-A[i];
        }
        sum = sum+solve(A);
        ans = max(ans,sum);
        for(i=0;i<n;i++)
            A[i]=-A[i];
        if(ans==0)
        {
            sort(A.begin(),A.end());
            return A[n-1];
        }
        // return max(ans,sum);
        return ans;
    }
};