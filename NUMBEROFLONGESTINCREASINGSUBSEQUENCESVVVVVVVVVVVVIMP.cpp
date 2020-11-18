class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==0) return 0;
        if(n==1)
            return 1;
        vector<int> len(n,0);
        vector<int> cnt(n,0);
        len[0]=1;
        cnt[0]=1;
        for(i=1;i<n;i++)
        {
            len[i]=cnt[i]=1;
            for(j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(len[i]<len[j]+1)
                        len[i]=len[j]+1, cnt[i]=cnt[j];
                    else if(len[i]==len[j]+1)
                        cnt[i]+=cnt[j];
                }
                    
            }
        }
        int lenmax = *max_element(len.begin(),len.end());
        cout<<lenmax<<endl;
        int ans=0;
        for(i=0;i<n;i++)
            if(len[i]==lenmax)
                ans+=cnt[i];
        return ans;
    }  
};