

/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.


*/


class Solution {
public:
    int solve(vector<int> &sum,int k)
    {
        int i,j,l,cursum=0,n=sum.size();
        set<int> st;
        st.insert(0);
        int ans=INT_MIN;
        for(i=0;i<n;i++)
        {
            cursum+=sum[i];
            auto pos = st.lower_bound(cursum-k);// smallest sum greater than (cursum-k)
            if(pos!=st.end())ans = max(ans,cursum-*pos);
            st.insert(cursum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int i,j,l,n=matrix.size();
        int m = matrix[0].size();
        vector<int> sum(n,0);
        int L,R;
        int ans=INT_MIN;
        for(L=0;L<m;L++)
        {
            sum = vector<int>(n,0);
            for(R =L;R<m;R++)
            {
                for(i=0;i<n;i++) sum[i]+=matrix[i][R];
                int x = solve(sum,k);
                ans = max(x,ans);
            }
        }
        return ans;
        
    }
};