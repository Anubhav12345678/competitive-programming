//2 pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        int ans=INT_MAX;
        deque<int> q;
        int sum=0,left=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=s){
                ans = min(ans,i-left+1);
                sum-=nums[left++];
            }
        }
        return (ans!=INT_MAX)? ans:0;
    }
};



class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==0)
            return 0;
        int S = accumulate(nums.begin(),nums.end(),0);
        if(s>S)
            return 0;
        if(s==S)
            return n;
        int left=0,right=0;
        int ans=INT_MAX;
        int sum=0;
        vector<int> cnt(n+1,0);
        for(i=1;i<=n;i++)
            cnt[i] = cnt[i-1]+nums[i-1];
        for(i=1;i<=n;i++)
        {
            l=i;
            int r = n;
            int cur;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(cnt[mid]-cnt[i-1]>=s)
                {
                    cur=mid-i+1;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            ans = min(ans,cur);
        }
        return ans;
    }
};






class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int i,j,k,l;
        if(n==0)
           return 0; 
        int minlen = INT_MAX;
        for(i=0;i<n;i++)
        {
            int cursum=nums[i];
            if(cursum>=s)
                return 1;
            for(j=i+1;j<n;j++)
            {
                cursum+=nums[j];
                if(cursum>=s&&(j-i+1)<minlen)
                    minlen = j-i+1;
            }
        }
        if(minlen!=INT_MAX)
        return minlen;
        return 0;
    }
};