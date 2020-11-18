
/*

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l]
 is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1
 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0





*/




class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int n = a.size();
        int i,j,k,l;
        map<int,int> mp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                mp[a[i]+b[j]]++;
            }
        }
        int res=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                int s = -(c[i]+d[j]);
                if(mp.find(s)!=mp.end())
                  res+=mp[s];  
            }
        }
        return res;
    }
};