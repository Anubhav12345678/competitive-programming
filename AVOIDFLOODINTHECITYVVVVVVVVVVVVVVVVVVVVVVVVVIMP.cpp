class Solution {
public:
    /*
Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake which is full of water, there will be a flood. Your goal is to avoid the flood in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes. (see example 4)

 

Example 1:

Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.



    */.
    vector<int> avoidFlood(vector<int>& rains) {
        int i,j,k,l,n=rains.size();
        map<int,int> mp;
        set<int> st;
        vector<int> ans(n);
        for(i=0;i<n;i++)
        {
            if(rains[i]>0)
            {
                if(mp.find(rains[i])==mp.end())
                {
                    ans[i]=-1;
                    mp[rains[i]]=i;
                }
                else
                {
                    j = mp[rains[i]];
                    auto it = st.upper_bound(j);
                    if(it==st.end())
                        return {};
                    else
                    {
                        ans[*it] = rains[i];
                        ans[i]=-1;
                        st.erase(it);
                    }
                    mp[rains[i]]=i;
                }
            }
            else
            {
                st.insert(i);
            }
        }
        for(i=0;i<n;i++)
            if(ans[i]==0) ans[i]=1;
        return ans;
    }
};