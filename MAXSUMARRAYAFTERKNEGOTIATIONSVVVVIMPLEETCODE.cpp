
/*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i],
 and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].




*/




class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
       priority_queue<int,vector<int>,greater<int>> pq(A.begin(),A.end());
        int i,j,k,l;
        int s=0;
        for(i=0;i<K;i++)
        {
            int val = pq.top();
            pq.pop();
            pq.push(-val);
        }
        while(!pq.empty())
        {
            s+=pq.top();
            pq.pop();
        }
        return s;
        
    }
};