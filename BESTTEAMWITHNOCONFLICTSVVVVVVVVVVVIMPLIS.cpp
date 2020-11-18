#define ff first
#define se second
class Solution {
public:
    
    // static bool comp(pair<int,int> a,pair<int,int> b)
    // {
    //     return a.se<b.se;
    // }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int i,j,k,l,n=scores.size();
        vector<pair<int,int>> v(n);
        for(i=0;i<n;i++)
            v[i] = {ages[i],scores[i]};
        sort(v.begin(),v.end());
        // for(i=0;i<n;i++)
        //     cout<<"v["<<i<<"].ff = "<<v[i].ff<<endl<<" v["<<i<<"].se "<<v[i].se<<endl;
        vector<int> lis(n,0);
        // for(i=0;i<n;i++)
        //     lis[i] = v[i].se;
        int ans=0;
        // ans=lis[0];
        for(i=0;i<n;i++)
        {
            lis[i] = v[i].se;
            for(j=0;j<i;j++)
            {
                // cout<<"i = "<<i<<endl;
                if(v[j].se>v[i].se) continue;
                lis[i] = max(lis[i],lis[j]+v[i].se);
            }
            // cout<<"lis["<<i<<"] = "<<lis[i]<<endl;
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};
/*
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

 

Example 1:

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.



*/