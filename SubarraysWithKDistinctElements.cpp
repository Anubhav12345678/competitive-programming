/*

Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different 
integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].


*/
class Solution {
public:
    // this fun returns no of subarrays hvng less than or equal to k distinct ele
    int solve(vector<int> &A,int k)
    {
        int i=0,j,l,res=0,n=A.size();
        map<int,int> cnt;
        for(j=0;j<n;j++)
        {
          if((cnt[A[j]]++)==0)
              k--;
            while(k<0)
            {
                cnt[A[i]]--;
                if(cnt[A[i]]==0)
                    k++;
                i++;
            }
            res+=(j-i+1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return solve(A,K)-solve(A,K-1);
    }
};