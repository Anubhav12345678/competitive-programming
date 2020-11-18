class Solution {
public:
    int candy(vector<int>& ratings) {
        int i,j,k,l,n=ratings.size();
        int ans=0;
        vector<int> left(n,1) ,right(n,1);
        for(i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                left[i]= left[i-1]+1;
        }
        
        for(i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                right[i] = right[i+1]+1;
        
        for(i=0;i<n;i++)
            ans+=max(left[i],right[i]);
        return ans;
    }
};
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.


*/