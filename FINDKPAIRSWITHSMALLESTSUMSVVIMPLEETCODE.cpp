
/*

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.




*/




class Solution {
public:
    static bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
    {
        return a.second<b.second;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int i,j,l;
        vector<int> p;
        
        vector<pair<pair<int,int>,int>> v;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                v.push_back(make_pair(make_pair(nums1[i],nums2[j]),nums1[i]+nums2[j]));
            }
        }
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> res;
        for(i=0;i<v.size()&&i<k;i++)
        {
            vector<int> tmp;
            tmp.push_back(v[i].first.first);
            tmp.push_back(v[i].first.second);
            res.push_back(tmp);
        }
        return res;
        // sort(p.begin(),p.end());
        
    }
};