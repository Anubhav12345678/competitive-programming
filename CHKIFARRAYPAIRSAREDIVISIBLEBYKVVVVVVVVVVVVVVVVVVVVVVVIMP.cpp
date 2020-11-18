class Solution {
public:
    /*

Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return True If you can find a way to do that or False otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).



    */
    bool canArrange(vector<int>& arr, int k) {
        int i,j,l,n=arr.size();
        vector<int> cnt(k,0);
        for(auto x:arr)
        {
            int y = x%k;
            if(y<0) y+=k;
            cnt[y]++;
        }
        if(cnt[0]%2) return 0;
        for(i=1;i<k;i++)
            if(cnt[i]!=cnt[k-i] ) return 0;
        return 1;
    }
};