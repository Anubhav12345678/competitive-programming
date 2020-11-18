

/*

Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).


*/










class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int i,j,k,l,sum=0;
        vector<int> r1,r2;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(nums[i]%3==1)
                r1.push_back(nums[i]);
            if(nums[i]%3==2)
                r2.push_back(nums[i]);
        }
        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());
        
        if(sum%3==0)
            return sum;
        if(sum%3==1)
        {
            int d = INT_MAX;
            if(r1.size()>=1)
                d = min(d,r1[0]);
            if(r2.size()>=2)
                d = min(d,r2[0]+r2[1]);
            return sum-d;
        }
        int d = INT_MAX;
        if(r1.size()>=2)
                d = min(d,r1[0]+r1[1]);
            if(r2.size()>=1)
                d = min(d,r2[0]);
            return sum-d;
        
        
    }
};




//me
class Solution {
public:
    int solve(vector<int> &v,int i1=-1,int i2=-1)
    {
        int i,j,k,l,n=v.size();
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(i!=i1&&i!=i2)
                ans+=v[i];
        }
        return ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        int ans=0;
        int x=-1,y=-1;
        int s = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),greater<>());
        if(s%3==0)
            return s;
        if(s%3==1)
        {
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]%3==1)
                    break;
            }
            int ans=solve(nums,i);
            int x=-1,y=-1;
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]%3==2)
                {
                    if(x==-1)
                      x=i;
                    else
                    {
                        y=i;
                        break;
                    }
                }
            }
            cout<<x<<" "<<y<<endl;
            if(x==-1||y==-1) return ans;
            return max(solve(nums,x,y),ans);
        }
        
        else{
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]%3==2)
                    break;
            }
            int ans=solve(nums,i);
            int x=-1,y=-1;
            for(i=n-1;i>=0;i--)
            {
                if(nums[i]%3==1)
                {
                    if(x==-1)
                      x=i;
                    else
                    {
                        y=i;
                        break;
                    }
                }
            }
            if(x==-1||y==-1) return ans;
            return max(ans,solve(nums,x,y));
        }
    }
};