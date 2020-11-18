    /*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.
    */
   #define ll long long int
class Solution {
public:
    ll merge(vector<ll> &v,ll l,ll m,ll r){
        ll i,j,k,n=v.size();
        i=l;
        j=m+1;
        ll cnt=0;
        for(i=l;i<=m;i++){
            while(j<=r&&(v[i]>(2*v[j])))
                j++;
            cnt+=(j-(m+1));
        }
        vector<int> tmp;
        k=0;
        i=l;
        j=m+1;
        while(i<=m&&j<=r){
            if(v[i]<=v[j])
                tmp.push_back(v[i++]);
            else
                tmp.push_back(v[j++]);
        }
        while(i<=m)
            tmp.push_back(v[i++]);
        while(j<=r)
           tmp.push_back(v[j++]);
        
        for(i=l;i<=r;i++)
            v[i]=tmp[i-l];
        return cnt;
            
    }
    ll mergesort(vector<ll> &v,ll l,ll r){
        if(l==r) return 0;
        ll m = (l+r)/2;
        ll inv = mergesort(v,l,m);
        inv+=mergesort(v,m+1,r);
        inv+=merge(v,l,m,r);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        vector<ll> v(nums.size());
        for(ll i=0LL;i<nums.size();i++){
            v[i] = (ll)(nums[i]);
        }
        return mergesort(v,0,v.size()-1);
    }
};