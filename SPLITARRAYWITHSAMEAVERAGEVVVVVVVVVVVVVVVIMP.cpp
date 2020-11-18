/*
In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value 
of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.


*/
class Solution {
public:
    bool isposs(vector<int> &v)
    {
        int s = accumulate(v.begin(),v.end(),0);
        for(int i=1;i<=v.size()/2;i++)
        {
            if((s*i)%v.size()==0) return 1;
        }
        return 0;
    }
    bool splitArraySameAverage(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int m = n/2;
        if(!isposs(A)) return 0;
        int sum = accumulate(A.begin(),A.end(),0);
        vector<set<int>> sums(m+1);
        sums[0].insert(0);
        for(auto num:A)
        {
            for(i=m;i>=1;i--)
            {
                for(auto t:sums[i-1])
                    sums[i].insert(t+num);
            }
        }
        for(i=1;i<=m;i++)
        {
            if((sum*i)%n==0&&  sums[i].find((sum*i)/n)!=sums[i].end()) return 1;
        }
        return 0;
    }
};