
/*

In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and 
simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return -1.

 

Example 1:

Input: A = [0,1,0], K = 1
Output: 2
Explanation: Flip A[0], then flip A[2].
Example 2:

Input: A = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
Example 3:

Input: A = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation:
Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]




*/

//BETTER
/*

Instead of using the queue, we can track the total number of flips, and use the source array to mark flips with negative values.

Note that we restore original values after the processing, so the source array is not changed.
*/
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K,int flips=0) {
        int i,j,k,l,n;
        int res=0;
        for(i=0;i<A.size();i++)
        {
            if(A[i]==flips%2)
            {
                if(i>A.size()-K)
                    return -1;
                res++;
                flips++;
                A[i]-=2;
            }
            if(i>=K-1&&A[i-K+1]<0) { flips--; A[i-K+1]+=2;};
        }
        return res;
    }
};






class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int i,j,k,l,n=A.size();
        int cur=0,ans=0;
        int event[n+1]={0};
        for(i=0;i<n;i++)
        {
          cur+=event[i];
          int x = (A[i]+cur)%2;
            if(x==0)
            {
                if(i+K-1>=n) return -1;
                ans++;
                cur++;
                event[i+K]--;
            }
        }
        return ans;
    }
};