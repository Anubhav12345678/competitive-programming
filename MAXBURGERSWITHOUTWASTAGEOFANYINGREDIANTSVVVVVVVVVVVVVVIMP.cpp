class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int i,j,k,l,m,n,lo,hi;
        int tot = cheeseSlices;
        hi = tot;
        lo=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int x = mid*4+(tot-mid)*2;
            if(x==tomatoSlices)
                return {mid,tot-mid};
            else if(x<tomatoSlices)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return {};
    }
};
/*
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.
Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining 
cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

 

Example 1:

Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]

Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
 There will be no remaining ingredients.

*/