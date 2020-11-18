class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int i,j,k,l,n=A.size();
        sort(A.begin(),A.end(),greater<>());
        int ans=0;
        for(i=0;i<n-2;i++)
        {
            if(A[i]<A[i+1]+A[i+2])
                ans = max(ans,A[i]+A[i+1]+A[i+2]);
        }
        return ans;
    }
};