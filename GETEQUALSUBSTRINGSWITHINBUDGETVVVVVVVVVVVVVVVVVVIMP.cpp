class Solution {
public:
    /*
    You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.



    */
    int equalSubstring(string s, string t, int maxCost) {
        if(maxCost==0)
        {
            int i;
            for(i=0;i<s.size();i++)
                if(s[i]!=t[i])
                    break;
            return i;
        }
        int i,j,k,l,n=s.size();
        int cost[n];
        for(i=0;i<s.size();i++)
        {
            cost[i] = abs(s[i]-t[i]);
        }
        int left=0;
        int right=0;
        int sum=0,ans=0;
        for(right=0;right<n;right++)
        {
            sum+=cost[right];
            while(left<=right&&sum>maxCost)
            {
                sum-=cost[left];
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
        
    }
};