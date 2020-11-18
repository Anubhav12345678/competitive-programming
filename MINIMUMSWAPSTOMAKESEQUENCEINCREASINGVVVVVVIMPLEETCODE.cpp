class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i,j,k,l,n=A.size();
        // int swap[1001]={1},noswap[1001]={0};
        
        vector<int> swap(n,n), noswap(n,n);
        swap[0]=1;
        noswap[0]=0;
        for(i=1;i<n;i++){
            // swap[i]=noswap[i]=n;
            if((A[i-1]<A[i])&&(B[i-1]<B[i]))
            {
                swap[i] = swap[i-1]+1;
                noswap[i] = noswap[i-1];
            }
             if((A[i-1]<B[i])&&(B[i-1]<A[i])){
                swap[i] = min(noswap[i-1]+1,swap[i]);
                noswap[i] = min(swap[i-1],noswap[i]);
            }
        }
        
        return min(swap.back(),noswap.back());
    }
};
/*
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.

*?