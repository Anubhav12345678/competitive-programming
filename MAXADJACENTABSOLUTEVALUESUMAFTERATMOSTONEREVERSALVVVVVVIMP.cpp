int solve(vector<int>& nums) {
   int i,j,k,l,n=nums.size();
   if(n<2) return 0;
   if(n==2) return abs(nums[1]-nums[0]);
   int def=0;
   for(i=1;i<n;i++) def+=abs(nums[i]-nums[i-1]);
   int res=def;
   for(i=n-2,j=n-1;i>=0;i--,j--)
   {
       int delta = abs(nums[i]-nums[j]);
       res = max(res,def-delta+abs(nums[j]-nums[0]));
       res = max(res,def-delta+abs(nums[i]-nums[n-1]));
   }
   int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
   for(i=1;i<n;i++)
   {
       int fi = abs(nums[i]-nums[i-1]);
       max1= max(max1,nums[i-1]+nums[i]-fi);
       min1= min(min1,nums[i-1]+nums[i]+fi);
       max2 = max(max2,nums[i-1]-nums[i]-fi);
       min2= min(min2,nums[i-1]-nums[i]+fi);
   }
   res=  max(res,def+max((max1-min1),(max2-min2)));
   return res;
}
/*
Intuition
Java implementation of xiaowuc1's design.

We need to find max of the followings possible reversals:

no sublist is reversed, noted as bydefault in the following
a sublist is reversed that starts from the beginning of the array
a sublist is reversed that ends at the ending of the array
a sublist is reversed that starts and ends in the middle
My simplification evolve into the followings

                [i-1][i]      [j-1][j]
               after switch will become
                [i-1][j-1]      [i][j]
  
          when                          simplify as
  ------------------------------------------------------------------
    [i-1]>[j-1] and [i]>[j]   [i-1]+[i]-f(i) - ([j-1] + [j] + f(j))
    [i-1]>[j-1] and [i]<[j]   [i-1]-[i]-f(i) - ([j-1] - [j] + f(j))
    [i-1]<[j-1] and [i]>[j]   [j-1]-[j]-f(j) - ([i-1] - [i] + f(i))
    [i-1]<[j-1] and [i]<[j]   [j-1]+[j]-f(j) - ([i-1] + [i] + f(i))
we can see the best improvement to the bydefault is
\max(max(
\ \ \ \max([i-1]+[i]-f(i)) - min([i-1]+[i]+f(i)) ,   max([i−1]+[i]−f(i))−min([i−1]+[i]+f(i)),
\ \ \ \max([i-1]-[i]-f(i)) - min([i-1]-[i]+f(i))   max([i−1]−[i]−f(i))−min([i−1]−[i]+f(i))
))

Implementation
The first for loop is to calculate the case for no sublist is reversed

The second for loop covers both reversal type 2 and 3 respectively (above)

The third for loop is to calculate the best improvement of the type 4 (see above)

Example #1
In the example 2, 3, 1, 5, 4, the max of the following, will reach the highest 8 when [i]=4, i.e. 5+4-1. the min of the following will reach the lowest 6 when [i]=3, i.e. 3+2-1.
\ \ \ \max([i-1]+[i]-f(i)) - min([i-1]+[i]+f(i)) ,   max([i−1]+[i]−f(i))−min([i−1]+[i]+f(i)),
therefore if we turn the array into 2,5,1,3,4 will reach the highest 10 sum of absolute difference.

Time Complexity
\mathcal{O}(n)O(n) we process the array three times.

Space Complexity
\mathcal{O}(1)O(1) we only use a few variables. no array



*/