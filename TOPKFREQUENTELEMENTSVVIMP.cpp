class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n)
            return nums;
        int i,j,l;
        map<int,int> m;
        for(i=0;i<n;i++)
            m[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
        }
        i=0;
        vector<int> res;
        while(i<k)
        {
            pair<int,int>  p = pq.top();
            pq.pop();
            if(find(res.begin(),res.end(),p.second)==res.end())
            res.push_back(p.second);
            i++;
        }
        return res;
        
    }
};