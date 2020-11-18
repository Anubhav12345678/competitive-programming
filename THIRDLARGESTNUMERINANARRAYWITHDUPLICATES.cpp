class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        vector<int> v;
        v.clear();
        map<int,int> mp;
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        for(auto it = st.begin();it!=st.end();it++)
            v.push_back(*it);
        n = v.size();
        cout<<"n = "<<n<<endl;
        if(n<3)
        {
            sort(v.begin(),v.end());
            return v[n-1];
        }
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int i,j,k,l;
        int first,second,third;
        first=v[0];
        for(i=1;i<n;i++)
            if(v[i]>first)
                first=v[i];
        
        second=third=INT_MIN;
        
        for(i=0;i<n;i++)
            if(v[i]>second&&v[i]<first)
                second=v[i];
        for(i=0;i<n;i++)
            if(v[i]>third&&v[i]<second)
                third = v[i];
        return third;
        
    }
};