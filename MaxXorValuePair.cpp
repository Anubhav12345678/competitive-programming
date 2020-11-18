class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int i,j,k,l;
        if(n<2)
            return 0;
        set<int> se;
        int mask=0,maxx=0;
        for(i=30;i>=0;i--)
        {
            mask|=(1<<i);
            for(int i=0;i<n;i++)
            {
                se.insert(nums[i]&mask);
            }
            int newmaxx = maxx|(1<<i);
            for(int pre:se)
            {
                if(se.count(newmaxx^pre))
                {
                    maxx=newmaxx;
                    break;
                }
            }
            se.clear();
        }
        return maxx;
    }
};