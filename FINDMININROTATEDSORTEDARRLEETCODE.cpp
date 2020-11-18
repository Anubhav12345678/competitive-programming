class Solution {
public:
    int findpiv(vector<int> &v,int l,int h)
    {
        if(l>h)
            return -1;
        if(l==h)
            return l;
        int m = (l+h)/2;
        if(m<h&&v[m]>v[m+1])
            return m;
        if(m>l&&v[m-1]>v[m])
            return m-1;
        if(v[l]>=v[m])
            return findpiv(v,l,m-1);
        else
            return findpiv(v,m+1,h);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i,j,k,l;
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
                break;
        }
        if(i==n-1)
            return nums[0];
        int piv = findpiv(nums,0,nums.size()-1);
        cout<<piv<<endl;
        if(piv==-1)
            return nums[0];
        else if(piv!=n-1)
            return nums[piv+1];
        else
            return nums[0];
        
    }
};

//part II where duplicates are present
class Solution {
public:
    int findMin(vector<int>& nums) {
       int left = 0,right = nums.size()-1,mid;
    while(left<right&&nums[left]>=nums[right]){
        mid = left+(right-left)/2;
        if(nums[mid]<nums[left])
            right = mid;
        else if(nums[mid]==nums[left]&&nums[mid]==nums[right]){
            left++;
            right--;
        }
        else
            left = mid+1;
    }
    return nums[left];
    }
};