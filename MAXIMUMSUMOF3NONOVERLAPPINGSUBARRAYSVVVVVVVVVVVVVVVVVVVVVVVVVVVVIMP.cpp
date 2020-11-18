class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int i,j,l,n=nums.size();
        vector<int> pre(n+1-k,0);
        for(i=0;i<k;i++)
            pre[0]+=nums[i];
        // k=1;
        for(i=1;i<=n-k;i++)
        {
            pre[i] = pre[i-1]+nums[i+k-1]-nums[i-1];
            // cout<<"pre["<<i<<"] = "<<pre[i]<<" nums["<<i+k-1<<"] = "<<nums[i+k-1]<<" nums["<<i-1<<"] = "<<nums[i-1]<<endl;
            // cout<<pre[i]<<endl;
        }
        // cout<<"ok\n";
        
        int left[n+1-k];
        int right[n+1-k];
        j=0;
        for(i=0;i<n+1-k;i++)
        {
            if(pre[i]>pre[j])
                j=i;
            left[i] = j;// max sum k len subarr ending at i
        }
        // cout<<"ok\n";
        j=(n+1-k)-1;
        for(i=(n+1-k)-1;i>=0;i--)
        {
            if(pre[i]>=pre[j])//lexographically smallest one dhundhna h 
                j=i;
            right[i] = j;
        }
        
        vector<int> res(3,-1);
        for(int b=k;b<(n+1-k)-k;b++)
        {
            int x = left[b-k];
            
            int y=  right[b+k];
            if(res[0]==-1||pre[x]+pre[b]+pre[y]>pre[res[0]]+pre[res[1]]+pre[res[2]])
            {
                res[0]=x;
                res[1]=b;
                res[2]=y;
            }
        }
        return res;
        
    }
};