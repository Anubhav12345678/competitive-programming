class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& a, int L, int M) {
        int i,j,k,l,n=a.size();
        int pre[n]={0};
        pre[0]=a[0];
        for(i=1;i<n;i++)
            pre[i]=pre[i-1]+a[i];
        int ans=0,cur=0,ans1=0;
        for(i=0;i<n-L+1;i++)
        {
            j=i+L-1;
            cur = (i==0)?pre[j]:(pre[j]-pre[i-1]);
            cout<<"i="<<"j="<<j<<" "<<i<<" cur="<<cur<<endl;
            for(k=i+L;k<n-M+1;k++)
            {
                l=k+M-1;
                int p = cur+(pre[l]-pre[k-1]);
                ans = max(ans,p);
            }
        }
        for(i=0;i<n-M+1;i++)
        {
           j=i+M-1;
            cur = (i==0)?pre[j]:(pre[j]-pre[i-1]);
            cout<<"i="<<"j="<<j<<" "<<i<<" cur="<<cur<<endl;
            for(k=i+M;k<n-L+1;k++)
            {
                l=k+L-1;
                int p = cur+(pre[l]-pre[k-1]);
                ans1 = max(ans1,p);
            } 
        }
        return max(ans,ans1);
    }
};