//O(N)
class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int i,j,k,l,n=v.size();
        if(n==0) return 0;
        vector<int> up(n);
        vector<int> down(n);
        up[0]=1;
        down[0]=1;
        for(i=1;i<n;i++)
        {
            if(v[i]>v[i-1])
            {
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            }
            else if(v[i]<v[i-1])
            {
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
            }
            else
            {
                up[i] = up[i-1];
                down[i]  =down[i-1];
            }
        }
        return max(up[n-1],down[n-1]);
    }
};



class Solution {
public:


    int wiggleMaxLength(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==0) return 0;
        int up[n],down[n];
        memset(up,1,sizeof(up));
        memset(down,1,sizeof(down));
        for(i=0;i<n;i++){
            up[i] = 0;
            down[i]=0;
        }
        up[0]=0;
        down[0]=0;
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(nums[i]>nums[j])
                up[i]  =max(up[i],down[j]+1);
                else if(nums[i]<nums[j])
                down[i] = max(down[i],up[j]+1);
            }
        }
        return 1+max(up[n-1],down[n-1]);
    }
};
/*

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate
 between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence 
 with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and
 negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences 
 are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is 
obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining 
elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.


*/