class Solution {
public:
    int countTriplets(vector<int>& A) {
        int i,j,k,l,n=A.size();
        int m = *max_element(begin(A),end(A));
        cout<<"m="<<m<<endl;
        vector<int> cnt(m+1,0);
        for(auto a:A)
        {
            for(auto b:A)
            {
                ++cnt[a&b];
            }
        }
        int ans=0;
        for(auto a:A)
        for(i=0;i<=m;i++)
        {
            if((a&i)==0) ans+=cnt[i];
        }
        return ans;
    }
};