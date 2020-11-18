class Solution {
public:
    int cnt[20000+10];
    int longestOnes(vector<int>& A, int K) {
        for (int i=1;i<=(int)A.size();++i){
            cnt[i]=cnt[i-1]+(A[i-1]==0);
        }
        int res=0;
        for (int i=1;i<=(int)A.size();++i){
            int l=i,r=(int)A.size(),ans=0;
            while (l<=r){
                int mid=l+((r-l)>>1);
                if (cnt[mid]-cnt[i-1]<=K){
                    l=mid+1;
                    ans=mid-i+1;
                }
                else r=mid-1;
            }
            res=max(res,ans);
        }
        return res;
    }
};