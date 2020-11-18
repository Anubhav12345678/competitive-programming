//QUESTION
/*
This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct,
 the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and
 individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
*/

//INTUTION
/*
Let arr_sorted be the arr array after being sorted. A "chunk" is an interval [i, j] such that arr[i], ..., arr[j] is just a
 permutation of arr_sorted[i], ..., arr_sorted[j]. Since each chunk is just a permutation, the sums of these two lists of
  numbers will be equal.
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i,j,k,l,n=arr.size();
        vector<int> v(arr.begin(),arr.end());
        sort(v.begin(),v.end());
        long long int ans=0,sum1=0,sum2=0;
        for(i=0;i<n;i++){
            sum1+=(long long int)v[i];
            sum2+=(long long int)arr[i];
            if(sum1==sum2) ans++;
        }
        return ans;
    }
};