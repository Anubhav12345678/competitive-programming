class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int i,j,k,l,n=row.size();
        if(n<=2)
            return 0;
        vector<int> pos(n);
        for(i=0;i<n;i++)
            pos[row[i]]=i;
        int cnt=0;
        for(i=0;i<n;i+=2){
            int me = row[i];
            int mycouple = (me&1)?me-1:me+1;// expected position of my couple            
            if(row[i+1]!=mycouple){
                cnt++;
                int neighbor = row[i+1];
                row[pos[mycouple]] = neighbor;
                pos[neighbor] = pos[mycouple];
            }
            
        }
        return cnt;
    }
};
/*
N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of
 swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the 
first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.



*/