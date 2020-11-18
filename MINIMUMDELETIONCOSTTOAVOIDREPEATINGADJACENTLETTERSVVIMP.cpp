class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int i,j,k,l,n=s.size();
        int ans=0;
        for(i=0;i<n;i++){
            // int mini=cost[i];
            j=i+1;
            while(j<n&&s[i]==s[j]) j++;
            // j--;
            vector<int> v;
            int maxi=0,sum=0;
            for(k=i;k<j;k++)
            {
                sum+=cost[k];
                maxi = max(maxi,cost[k]);
            }
            ans+=sum-maxi;
            i=j-1;
                // v.push_back(cost[j]);
            // sort();
        }
        
        return ans;
    }
};
/*
Given a string s and an array of integers cost where cost[i] is the cost of deleting the character i in s.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

 

Example 1:

Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).
*/