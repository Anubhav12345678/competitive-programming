

/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.




*/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1) return 1;
        int i,j,k,l,n=trust.size();
        map<int,vector<int>> mp;
        set<int> st;
        for(auto it:trust)
        {
            mp[it[0]].push_back(it[1]);
        }
        for(i=1;i<=N;i++)
            if(mp.find(i)==mp.end())
                st.insert(i);
        if(st.size()==0)
            return -1;
        map<int,vector<int>> mp2;
        for(i=0;i<n;i++)
        {
            if(st.find(trust[i][1])!=st.end())
                mp2[trust[i][1]].push_back(trust[i][0]);
        }
        
        int cnt=0;
        vector<int> v1;
        for(auto it=mp2.begin();it!=mp2.end();it++)
        {
           vector<int> tmp = it->second;
            if(tmp.size()==N-1)
                v1.push_back(it->first);
        }
        if(v1.size()==0||v1.size()>1)
            return -1;
        return v1[0];
        
            
    }
};