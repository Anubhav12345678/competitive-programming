class Solution {
public:
    /*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.


    */
    int kadane(vector<int> &v)
    {
        int i,j,k,l,n=v.size();
        int maxtillhere=0;
        int maxsofar=0;
        for(i=0;i<n;i++)
        {
            maxtillhere+=v[i];
            if(maxtillhere<0) maxtillhere=0;
            maxsofar = max(maxsofar,maxtillhere);
        }
        if(maxsofar==0)
        {
            sort(v.begin(),v.end());
            return v[n-1];
        }
        return maxsofar;
    }
    int maximumSum(vector<int>& v) {
        int i,j,k,l,n=v.size();
        if(n==1) return v[0];
        vector<int> left(n,0);
        vector<int> right(n,0);
        int ans = kadane(v);
        if(ans<=0) return ans;
        left[0]=0;
        for(i=1;i<n;i++)
        {
            left[i] = max(left[i-1]+v[i-1],0);
        }
        right[n-1] = 0;
        for(i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1]+v[i+1],0);
        }
        for(i=0;i<n;i++)
        {
            ans =max(ans,left[i]+right[i]);
        }
        return ans;
        
    }
};