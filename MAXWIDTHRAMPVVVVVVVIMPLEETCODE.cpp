

/*
Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.




*/


class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
       class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
       vector<int> s;
        int best = 0;
        for(int i=0;i<A.size();i++) {
            if(s.empty() || A[s.back()] > A[i]) s.push_back(i);
            int l=0, r=s.size()-1;
            int ans=0;
            while(l<=r) {
                int m = (l+r)/2;
                if(A[s[m]] <= A[i]) {
                    ans = i - s[m];
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            best = max(best, ans);
        }
        return best;
    }
};
    }
};