/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
/*
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is 
sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 
in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions 
that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. 
You will not have access the binary matrix directly.


*/
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int i,j,k,l,n,m;
        vector<int> d = binaryMatrix.dimensions();
        n= d[0];
        m = d[1];
        int h=m-1;
        l=0;
        int ans=-1;
        cout<<"ok\n";
        while(l<=h)
        {
            int mid = (l+h)/2;
            for(i=0;i<n;i++)
                if(binaryMatrix.get(i,mid)==1)
                    break;
            if(i==n)
                l=mid+1;
            else
            {
                ans=mid;
                h=mid-1;
            }
        }
        return ans; 
        
    }
};