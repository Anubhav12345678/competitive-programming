class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int i,j,k,l,n=A.size();
        int m = A[0].size();
        set<int> st;
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st.count(j)>0||A[i-1][j]==A[i][j]) continue;
                if(A[i-1][j]>A[i][j])
                {
                    st.insert(j);
                    i=0;
                }
                break;
            }
        }
        return st.size();
    }
};
/*

int minDeletionSize(vector<string>& A) {
    unordered_set<int> di;
    for (auto i = 1; i < A.size(); ++i) {
        for (auto j = 0; j < A[i].size(); ++j) {
            if (di.count(j) > 0 || A[i - 1][j] == A[i][j]) continue;
            if (A[i - 1][j] > A[i][j]) {
                di.insert(j);
                i = 0;
            }
            break;
        }
    }
    return di.size();
}
*/
/*

We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.

 

Example 1:

Input: ["ca","bb","ac"]
Output: 1
Explanation: 
After deleting the first column, A = ["a", "b", "c"].
Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
We require at least 1 deletion since initially A was not in lexicographic order, so the answer is 1.

*/