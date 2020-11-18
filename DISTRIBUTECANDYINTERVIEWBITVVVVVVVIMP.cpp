int Solution::candy(vector<int> &ratings) {
    int i,j,k,l,n=ratings.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    for(l=1;l<n;l++)
    if(ratings[l]>ratings[l-1])
    left[l] = left[l-1]+1;
    for(int r=n-2;r>=0;r--)
    if(ratings[r]>ratings[r+1])
    right[r] = right[r+1]+1;
    // vector<int> res(n);
    int s=0;
    for(i=0;i<n;i++)
    s+=   max(left[i],right[i]);
    return s;
    
}
/*

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?s
*/