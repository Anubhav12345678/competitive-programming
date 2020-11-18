// vector<int> left(vector<int> &v)
// {
//     int i,j,k,l,n=v.size();
//     stack<int> st;
//     vector<int> res(n);
//     for(i=0;i<n;i++)
//     {
//         while(!st.empty()&&v[i]<)
//     }
// }

int solve(vector<int>& nums) {
    int i,j,k,l,n=nums.size();
    map<int,int> larger;
    int mx=INT_MIN;
    vector<pair<int,int>> v(n);
    for(i=n-1;i>=0;i--)
    {
        if(mx>=nums[i])
        larger[i] = mx;
        v[i] = {nums[i],i};
        mx = max(mx,nums[i]);
    }
    
    sort(v.begin(),v.end());
    int res=0;
    stack<int> st;
    for(i=0;i<n;i++)
    {
        auto p  = v[i];
        if(larger.count(p.second))
        {
            while(!st.empty()&&p.second<v[st.top()].second)
            st.pop();
            if(!st.empty())
            res =max(res, p.first+larger[p.second]+nums[v[st.top()].second]);
            st.push(i);
        }
    }
    return res;
}
/*
Given a list of positive integers nums, consider three indices i < j < k such that nums[i] ≤ nums[j] ≤ nums[k]. Return the maximum possible nums[i] + nums[j] + nums[k]. You can assume that a solution exists.

Constraints

3 ≤ n ≤ 100,000 where n is the length of nums



*/