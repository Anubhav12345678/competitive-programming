
/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.





*/




class Solution {
public:
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(helper(A, B), helper(B, A));
    }
    int helper(vector<vector<int>>& A, vector<vector<int>>& B){
        int overlap = 0;
        int n = A.size();
        for(int x = 0; x < n; ++x){
            for(int y = 0; y < n; ++y){
                int count = 0;
                for(int ia = 0, ib = x; ib < n; ++ia, ++ib){
                    for(int ja = 0, jb = y; jb < n; ++ja, ++jb){
                        count += (A[ia][ja] & B[ib][jb]);
                    }
                }
                overlap = max(overlap, count);
            }
        }
        return overlap;
    }
};