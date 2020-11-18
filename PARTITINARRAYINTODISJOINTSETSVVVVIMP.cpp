


/*

Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

*/



class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int left[n],right[n];
        left[0] = A[0];
        right[n-1] = A[n-1];
        for(i=1,j=n-2;i<n,j>=0;i++,j--)
        {
            left[i]  =max(left[i-1],A[i]);
            // cout<<"left["<<i<<"] = "<<left[i]<<" ";
            // right[j] = min(right[j+1],A[j]);
        }
        
        for(i=n-2;i>=0;i--)
        {
            right[i] = min(right[i+1],A[i]);
            // cout<<"right["<<i<<"] = "<<right[i]<<" ";
        }
        for(i=1;i<n;i++)
        {
            cout<<"left["<<i<<"] = "<<left[i]<<" right["<<i<<"] = "<<right[i]<<endl;
            if(left[i-1]<=right[i])
                break;
        }
        return i;
    }
};