/*

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino. 
 (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:



Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.






*/




class Solution {
public:
    int solve(vector<int> a,vector<int> b)
    {
        int i,j,k,l,n=a.size();
        map<int,int> mp1,mp2;
        for(i=0;i<n;i++)
        {
            mp1[a[i]]++;
            mp2[b[i]]++;
        }
        int ma=mp1[a[0]],ele1=a[0],mb = mp2[b[0]],ele2=b[0];
        for(i=1;i<n;i++)
        {
            if(mp1[a[i]]>ma)
            {
                ma= mp1[a[i]];
                ele1 = a[i];
            }
            if(mp2[b[i]]>mb)
            {
                mb = mp2[b[i]];
                ele2=b[i];
            }
        }
        k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=ele1)
            {
                if(b[i]==ele1)
                    k++;
            }
        }
        return (k==n-ma)?k:INT_MAX;
        // for(auto it = mp1.begin();it!=mp1.end();it++)
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int x = solve(A,B);
        int y =  solve(B,A);
        if(min(x,y)==INT_MAX)
            return -1;
        else
            return min(x,y);
    }
};