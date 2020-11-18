class Solution {
public:


    /*
  Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1



    */
    int shortestSubarray(vector<int>& A, int K) {
        int i,j,k,l,n=A.size();
        int res=n+1;
        vector<int> pre(n+1,0);
        deque<int> q;
        for(i=0;i<n;i++)
        {
            pre[i+1] = pre[i]+A[i];
        }
        for(i=0;i<=n;i++)
        {
            while(q.size()>0&&pre[i]-pre[q.front()]>=K)
            {
                res=min(res,i-q.front());
                q.pop_front();
            }
            
            while(q.size()>0&&pre[i]<=pre[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        
        
        return (res==n+1)?-1:res;
    }
};