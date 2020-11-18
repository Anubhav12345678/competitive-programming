#define ll long  long
class Solution {
public:
    /*
   
User Accepted:260
User Tried:301
Total Accepted:260
Total Submissions:328
Difficulty:Medium
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden.
 If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.




    */
    bool solve(ll mid,vector<int> &v,int m,int k)
    {
        int tot=0,i,j,l,n=v.size();
        vector<bool> res(n);
        // cout<<"mid = "<<mid<<endl;
        for(i=0;i<n;i++) res[i] = (v[i]<=mid);
        for(i=0;i<res.size();){
            if(res[i]==0)
                i++;
            j=i;
            while(j<n&&res[j]==1&&j-i<k)
                j++;
            if(j-i>=k)
                tot++;
            i=j;
        }
        return tot>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        if(m*k>v.size()) return -1;
        int i,j,n=v.size();
         ll ans=-1,l=1LL,r=(ll)*max_element(v.begin(),v.end());
        cout<<r;
        while(l<=r){
            int mid=  (l+r)>>1;
            if(solve(mid,v,m,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};