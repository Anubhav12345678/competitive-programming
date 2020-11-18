class Solution {
public:
    vector<string> alertNames(vector<string>& kn, vector<string>& kt) {
        int i,j,k,l,n=kn.size(),m;
        map<string,vector<int>> mp;
        for(i=0;i<n;i++)
        {
            int h = (kt[i][0]-'0')*10+(kt[i][1]-'0');
            int m=  (kt[i][3]-'0')*10+(kt[i][4]-'0');
            mp[kn[i]].push_back(h*60+m);
        }
        vector<string> res;
        for(auto it:mp)
        {
            // vector<int> v = it->second;
            if(it.second.size()<3) continue;
            vector<int> v = it.second;
            string s = it.first;
            sort(v.begin(),v.end());
            bool ok=0;
            // for(i=0;i<v.size();i++)
            //     cout<<v[i]<<" ";
            // cout<<endl;
            for(i=0;i<v.size()-2;i++)
            {
                if((v[i+2]-v[i])<=60)
                {
                    ok=1;
                    break;
                }
            }
            if(ok)
                res.push_back(s);
        }
        return res;
        
    }
};
/*
Leetcode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "23:51" - "00:10" is not considered to be within a one-hour period.

 

Example 1:

Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").


*/