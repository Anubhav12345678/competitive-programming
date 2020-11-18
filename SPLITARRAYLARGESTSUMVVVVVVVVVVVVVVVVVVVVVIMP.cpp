/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m 
non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.





*/




class Solution {
public:
    bool cansplit(vector<int> &v,long long int tar,int m)
    {
        int i,j,k,l;
        long long int sum=0;
        int cnt=1;
        for(i=0;i<v.size();i++)
        {
            sum+=(long long int)v[i];
            if(sum>tar)
            {
                cnt++;
                sum=(long long int)v[i];
                if(cnt>m)
                    return 0;
            }
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int m) {
        int i,j,k,l,n=nums.size();
        long long int left = (long long int )*max_element(nums.begin(),nums.end());
        long long int right=  accumulate(nums.begin(),nums.end(),0LL);
        while(left<=right)
        {
            long long int mid = left+(right-left)/2;
            if(cansplit(nums,mid,m))//with sum as mid we can less than or equal to m so increase the partitions decrease right
                right=  mid-1;
            else // we cant split
                left = mid+1;
        }
        return left;
    }
};